# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    data_pipeline.py                                  :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 18:47:36 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:51:23 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod
from typing import Any, Protocol


class DataProcessor(ABC):

    def __init__(self) -> None:
        self.data: list[Any] = []
        self.rank: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.data:
            raise IndexError("No data available")
        value = self.data.pop(0)
        current_rank = self.rank
        self.rank += 1
        return (current_rank, str(value))


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(isinstance(item, (int, float)) for item in data)
        return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, (int, float)):
            self.data.append(str(data))
        else:
            for item in data:
                self.data.append(str(item))

    def get_count(self) -> int:
        return self.rank + len(self.data)


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, str):
            self.data.append(data)
        else:
            for item in data:
                self.data.append(item)

    def get_count(self) -> int:
        return self.rank + len(self.data)


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(
                    isinstance(k, str) and isinstance(v, str)
                    for k, v in data.items())
        if isinstance(data, list):
            return all(
                    isinstance(item, dict) and
                    all(
                        isinstance(k, str) and isinstance(v, str)
                        for k, v in item.items())
                    for item in data)
        return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, dict):
            formatted = f"{data.get('log_level', 'INFO')}: " \
                       f"{data.get('log_message', '')}"
            self.data.append(formatted)
        else:
            for item in data:
                formatted = f"{item.get('log_level', 'INFO')}: " \
                           f"{item.get('log_message', '')}"
                self.data.append(formatted)

    def get_count(self) -> int:
        return self.rank + len(self.data)


class ExportPlugin(Protocol):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        values = [value for _, value in data]
        csv_line = ",".join(values)
        print(f"CSV Output:\n{csv_line}")


class JSONExportPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        json_dict = {f"item_{rank}": value for rank, value in data}
        json_str = "{"
        items = [f'"{k}": "{v}"' for k, v in json_dict.items()]
        json_str += ", ".join(items)
        json_str += "}"
        print(f"JSON Output:\n{json_str}")


class DataStream:
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            processed = False
            for processor in self.processors:
                if processor.validate(element):
                    processor.ingest(element)
                    processed = True
                    break
            if not processed:
                print(f"DataStream error - Can't process element in stream: "
                      f"{element}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        has_processors = False
        for processor in self.processors:
            name = processor.__class__.__name__
            total = processor.rank + len(processor.data)
            remaining = len(processor.data)
            if total > 0 or remaining > 0:
                print(f"{name}: total {total} items processed, "
                      f"remaining {remaining} on processor")
                has_processors = True
        if not has_processors:
            print("No processor found, no data")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self.processors:
            data_to_export: list[tuple[int, str]] = []
            for _ in range(nb):
                if processor.data:
                    data_to_export.append(processor.output())
            if data_to_export:
                plugin.process_output(data_to_export)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print("Initialize Data Stream...")
    stream = DataStream()

    print("== DataStream statistics ==")
    stream.print_processors_stats()

    print("Registering Processors")
    stream.register_processor(NumericProcessor())
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())

    test_stream: list[Any] = [
        'Hello world',
        [3.14, -1, 2.71],
        [{'log_level': 'WARNING',
          'log_message': 'Telnet access! Use ssh instead'},
         {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
        42,
        ['Hi', 'five']
    ]

    print(f"Send first batch of data on stream: {test_stream}")
    stream.process_stream(test_stream)

    stream.print_processors_stats()

    print("Send 3 processed data from each processor to a CSV plugin:")
    csv_plugin: ExportPlugin = CSVExportPlugin()
    stream.output_pipeline(3, csv_plugin)

    stream.print_processors_stats()

    test_stream_2: list[Any] = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [{'log_level': 'ERROR', 'log_message': '500 server crash'},
         {'log_level': 'NOTICE',
          'log_message': 'Certificate expires in 10 days'}],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]

    print(f"Send another batch of data: {test_stream_2}")
    stream.process_stream(test_stream_2)

    stream.print_processors_stats()

    print("Send 5 processed data from each processor to a JSON plugin:")
    json_plugin: ExportPlugin = JSONExportPlugin()
    stream.output_pipeline(5, json_plugin)

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
