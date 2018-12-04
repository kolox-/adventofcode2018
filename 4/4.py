import sys
import re
from collections import defaultdict, Counter

def parse_line(regex, line):
    m = regex.match(line)
    if m:
        return int(m.group(1))


# Init regex for line parsing
guard_id_re = re.compile(r'^\[.*\] Guard #(\d+) begins shift$')
mins_re = re.compile(r'^\[\d+-\d+-\d+ \d+:(\d+)\].*$')

# Store the events and sort them chronologically
events = [line.strip() for line in sys.stdin]
events.sort()

# Parse the events and increment the counts for minutes each guard was asleep
guards = defaultdict(Counter)
for event in iter(events):
    if 'begins shift' in event:
        current_id = parse_line(guard_id_re, event)
    elif 'falls asleep' in event:
        start = parse_line(mins_re, event)
    elif 'wakes up' in event:
        end = parse_line(mins_re, event)
        for i in range(start, end):
            guards[current_id][i] += 1

# Init dummy values to hold the max result
max_strat_1 = (-1, -1, -1, -1)
max_strat_2 = (-1, -1, -1, -1)

# Complete both strategies in one pass
for id, mins in guards.items():
    total = sum(mins.values())
    minute, count = mins.most_common(1)[0] # Counter.most_common returns: [(key, count)]

    # Strategy 1
    if total > max_strat_1[1]:
        max_strat_1 = (id, total, minute, id*minute)

    # Strategy 2
    if count > max_strat_2[2]:
        max_strat_2 = (id, minute, count, id*minute)

# Output
print("Strategy 1: Guard {} was sleepiest with a total of {} mins. Most common min: {}. Result (id x min): {}".format(*max_strat_1))
print("Strategy 2: Guard {} was most commonly asleep on the same minute: {} times on minute {}. Result (id x min): {}".format(*max_strat_2))
