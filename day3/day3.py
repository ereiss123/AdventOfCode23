"""
Day 3: Engine Parts
"""

def part1(debug=False):
    if debug:
        file = "test.txt"
    else:
        file = "input.txt"
    with open(file, "r") as f:
        mat = []
        for line in f:
            mat.append(line.strip().)