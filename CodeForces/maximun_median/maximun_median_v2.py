def check_moves_for_k(array, k_for_test, max_k_operations):
    moves = 0
    for i in range(len(array) // 2, len(array)):
        if k_for_test - array[i] > 0:
            moves += k_for_test - array[i]
        if k_for_test - array[i] <= 0:
            return True
        if moves > max_k_operations:
            return False

    return True


def solve(k):
    array = list(map(int, input().split(" ")))
    array.sort()
    min_k = 1
    max_k = ((10**9) * 2) + 1
    while min_k < max_k:
        mid_k = (max_k + min_k + 1) // 2
        if check_moves_for_k(array, mid_k, k):
            min_k = mid_k
        else:
            max_k = mid_k - 1

    return min_k


def main():
    _, k = map(int, input().split())
    print(solve(k))


main()
