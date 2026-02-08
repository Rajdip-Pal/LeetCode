from typing import List
from heapq import heappop, heappush


class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()  # sorting events by their start day and then by end day

        min_heap = []
        event_index = 0
        attended_events = 0
        total_events = len(events)
        current_day = 0

        while event_index < total_events:

            if not min_heap:
                current_day = max(current_day, events[event_index][0])

            while event_index < total_events and events[event_index][0] == current_day:
                heappush(min_heap, events[event_index][1])
                event_index += 1

            while min_heap:
                earliest_end = heappop(min_heap)
                if earliest_end >= current_day:
                    attended_events += 1
                    break

            current_day += 1

        while min_heap:
            earliest_end = heappop(min_heap)
            if earliest_end >= current_day:
                attended_events += 1
                current_day += 1

        return attended_events
