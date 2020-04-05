# import sys #debugging purposes


def main():
    # sys.stdin = open('in', 'r') 
    for cases in range(int(input())):
        matrix = []
        N = int(input())
        for _ in range(N):
            matrix.append(input().split(' '))

        k = 0
        r = 0
        c = 0
        repeted_row = set()
        repeted_column = set()
        for i in range(N):
            for j in range(N):
                elem = matrix[i][j]
                if i == j:
                    k += int(elem)
                if matrix[i].count(elem) > 1 and i not in repeted_row:
                    repeted_row.add(i)
                    r += 1
                if j not in repeted_column:
                    for row in range(len(matrix)):
                        if i != row and elem == matrix[row][j]:
                            repeted_column.add(j)
                            c += 1 
                            break

        print('Case #{0}: {1} {2} {3}'.format(cases+1, k,r,c))

main()
