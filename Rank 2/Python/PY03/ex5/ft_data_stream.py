# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_data_stream.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 16:00:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/30 17:10:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

import random
import typing


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    players: list[str]
    actions: list[str]

    players = ["alice", "bob", "charlie", "dylan"]
    actions = ["run", "eat", "sleep", "grab", "move", "climb", "swim",
               "use", "release"]
    while (True):
        yield (random.choice(players), random.choice(actions))


def consume_event(events: list[tuple[str, str]]
                  ) -> typing.Generator[tuple[str, str], None, None]:
    chosen: tuple[str, str]

    while (len(events) > 0):
        chosen = random.choice(events)
        events.remove(chosen)
        yield chosen


def print_events(count: int) -> None:
    stream: typing.Generator[tuple[str, str], None, None]
    event: tuple[str, str]
    i: int

    stream = gen_event()
    i = 0
    while (i < count):
        event = next(stream)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")
        i += 1


def build_events(count: int) -> list[tuple[str, str]]:
    stream: typing.Generator[tuple[str, str], None, None]
    events: list[tuple[str, str]]
    i: int

    stream = gen_event()
    events = []
    i = 0
    while (i < count):
        events.append(next(stream))
        i += 1
    return (events)


def consume_all(events: list[tuple[str, str]]) -> None:
    consumer: typing.Generator[tuple[str, str], None, None]
    event: tuple[str, str]

    consumer = consume_event(events)
    while (len(events) > 0):
        event = next(consumer)
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events}")


def main() -> int:
    events: list[tuple[str, str]]

    print("=== Game Data Stream Processor ===")
    print_events(1000)
    events = build_events(10)
    print(f"Built list of 10 events: {events}")
    consume_all(events)
    return (0)


if (__name__ == "__main__"):
    main()
