from collections import deque
import math


def solve(attacks):
    ships = list(map(int, input().split()))
    if sum(ships) <= attacks:
        return(len(ships))

    left_removes, right_removes = (attacks + 1) // 2, attacks // 2
    i = j = 0;
    while i < len(ships) and ships[i] <= left_removes:
        left_removes -= ships[i]
        i += 1
    while j < len(ships) and ships[~j] <= right_removes:
        right_removes -= ships[~j]
        j += 1
    return i + j


def main():
    test_cases = int(input())
    for _ in range(test_cases):
        _, attacks = map(int, input().split())
        print(solve(attacks))


main()
