import re
import sys

claimed = set()
shared = set()

def process_coords(id, left_dist, top_dist, width, height):
    for i in xrange(left_dist, left_dist + width):
        for j in xrange(top_dist, top_dist + height):
            current = (i, j)
            if current in claimed:
                shared.add(current)
            else:
                claimed.add(current)

regex = re.compile(r'^#(\d+) @ (\d+),(\d+): (\d+)x(\d+)$')
for line in sys.stdin:
    match = regex.match(line.strip())
    args = [int(x) for x in match.groups()]
    process_coords(*args)

print("{} inches overlapping".format(len(shared)))
