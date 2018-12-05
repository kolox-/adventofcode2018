import sys
import re
from string import ascii_lowercase

def annihilates(first, second):
    # Does this pair of chars annihilate with eachother?
    if first.lower() == second.lower():
        # Same base char
        if (first.isupper() and second.islower()) or \
           (first.islower() and second.isupper()):
           # Polarised
           return True
    return False

def react_polymer(polymer, ignored_chars=''):
    stack = []
    for char in polymer:
        if char in ignored_chars:
            # Star2: We're acting as if these don't exist
            continue
        if len(stack) == 0:
            stack.append(char)
        elif annihilates(stack[-1], char):
            stack.pop()
        else:
            stack.append(char)
    return stack

polymer = sys.stdin.readline()

 # Star 1
stack = react_polymer(polymer)
print("Star1: Polymer of length {} reacts to become length {}".format(len(polymer), len(stack)))

# Star 2
min_ = len(stack)
for char in ascii_lowercase:
    length = len(react_polymer(polymer, ignored_chars=char+char.upper()))
    if length < min_:
        min_ = length
        min_char = char

print("Star2: After removing pair {}, the polymer reacts to become length {}".format(min_char + min_char.upper(), min_))
