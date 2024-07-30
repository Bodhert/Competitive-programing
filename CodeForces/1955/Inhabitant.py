from collections import deque
import math


def solve(attacks):
    ships = deque(map(int, input().split()))
    ships_len = len(ships)
    while attacks > 0 and len(ships) > 1:
        min_durability = min(ships[0], ships[-1])
        if attacks < 2 * min_durability:
            ships[0] -= math.ceil(attacks / 2)
            ships[-1] -= attacks // 2
            attacks = 0
        else:
            ships[0] -= min_durability
            ships[-1] -= min_durability
            attacks -= min_durability * 2

        if ships[0] == 0:
            ships.popleft()
        if ships[-1] == 0:
            ships.pop()

    ans = ships_len - len(ships)

    if len(ships) and ships[0] <= attacks:
        ans += 1
    return ans


def main():
    test_cases = int(input())
    for _ in range(test_cases):
        _, attacks = map(int, input().split())
        print(solve(attacks))


main()
