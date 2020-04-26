import math
def main():
    n, k =  map(int,input().split(' '))
    radious = []
    for _ in range(n):
        x,y,z = map(float, input().split(' '))
        radious.append(math.sqrt(x**2 + y**2 + z**2))
    radious.sort()
    print(f'{radious[k-1]}')

main()
