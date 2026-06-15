# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    data_stream.py                                    :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 18:35:01 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:50:35 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod
from typing import Any


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


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print("Initialize Data Stream...")
    stream = DataStream()

    print("== DataStream statistics ==")
    stream.print_processors_stats()

    print("Registering Numeric Processor")
    stream.register_processor(NumericProcessor())

    test_stream: list[Any] = [
                'Hello world',
                [3.14, -1, 2.71],
                [{'log_level': 'WARNING',
                  'log_message': 'Telnet access! Use ssh instead'},
                    {'log_level': 'INFO',
                     'log_message': 'User wil is connected'}],
                42,
                ['Hi', 'five']
        ]

    print(f"Send first batch of data on stream: {test_stream}")
    stream.process_stream(test_stream)

    stream.print_processors_stats()

    print("Registering other data processors")
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())

    print("Send the same batch again")
    stream.process_stream(test_stream)

    stream.print_processors_stats()

    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    for _ in range(3):
        if stream.processors[0].data:
            stream.processors[0].output()
    for _ in range(2):
        if stream.processors[1].data:
            stream.processors[1].output()
    for _ in range(1):
        if stream.processors[2].data:
            stream.processors[2].output()

    stream.print_processors_stats()

    print("\nHow does polymorphism allow the DataStream to handle "
          "different data types in the stream without knowing their "
          "specific implementations?")
    print("What are the benefits of this design approach?")


if __name__ == "__main__":
    main()
