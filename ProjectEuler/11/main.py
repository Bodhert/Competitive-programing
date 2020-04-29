import math
n = 20
di = [1,1,0,-1,-1,-1,0,1]
dj = [0,1,1,1,0,-1,-1,-1]

def recuresive_mult(mat, i, j, depth, orientation):
    if (i < 0 or i >= n or j < 0 or j >= n or depth >= 4):
        return 1

    return mat[i][j] * recuresive_mult(mat,i + di[orientation], j+dj[orientation], depth + 1, orientation)

    

def main():
    # n = 20
    mat = [list(map(int,input().split(' '))) for _ in range(n)]
    
    maxi = -math.inf 
    for i in range(n):
        for j in range(n):
            for k in range(8):
                p = recuresive_mult(mat,i,j,0,k)
                maxi = max(maxi,p)

    print(maxi)


main()
