# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_ints.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 16:14:30 by Elkan Choo        #+#    #+#              #
#    Updated: 2025/12/26 17:30:15 by Elkan Choo       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env python3

import sys
import random

INT_MIN = -2**31
INT_MAX =  2**31 - 1

def main():
    if len(sys.argv) < 2:
        print("Usage: gen_unique_ints.py <count> [seed]", file=sys.stderr)
        sys.exit(1)

    count = int(sys.argv[1])
    if count > 500:
        raise ValueError("Maximum count is 500")

    if len(sys.argv) > 2:
        random.seed(int(sys.argv[2]))

    nums = set()
    while len(nums) < count:
        nums.add(random.randint(INT_MIN, INT_MAX))

    print(" ".join(map(str, nums)))

if __name__ == "__main__":
    main()

