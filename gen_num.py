#!/usr/bin/env python3

import sys
import random

INT_MIN = -2**31
INT_MAX =  2**31 - 1

def main():
    if len(sys.argv) < 2:
        print("Usage: gen_num.py <count> [seed]", file=sys.stderr)
        sys.exit(1)

    if len(sys.argv) > 2:
        random.seed(int(sys.argv[2]))

    nums = set()
    while len(nums) < count:
        nums.add(random.randint(INT_MIN, INT_MAX))

    print(" ".join(map(str, nums)))

if __name__ == "__main__":
    main()
