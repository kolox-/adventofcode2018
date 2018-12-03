import re
import sys
from collections import defaultdict

coords = defaultdict(list)

def process_coords(id, left_dist, top_dist, width, height):
    for i in xrange(left_dist, left_dist + width):
        for j in xrange(top_dist, top_dist + height):
            current = (i, j)
            coords[current].append(id)
            
regex = re.compile(r'^#(\d+) @ (\d+),(\d+): (\d+)x(\d+)$')
id_list = []
for line in sys.stdin:
    match = regex.match(line.strip())
    args = [int(x) for x in match.groups()]
    id_list.append(args[0])
    process_coords(*args)

disqualified = set()
for coord, ids in coords.items():
    if len(ids) > 1:
        disqualified |= set(ids)

for val in id_list:
    if val not in disqualified:
        print("Claim ID {} not disqualified".format(val))
