# import sys #debugging purposes
def main():
    # sys.stdin = open('in.txt', 'r') 
    for tc in range(int(input())):
        x, y = map(int, input().split(' '))
        if (x+y) % 2 == 0:
            print('Case #{}: {}'.format(tc+1,'IMPOSSIBLE'))
        else:
            ans = []
            while True:
                # print(x, y)
                if x % 2 == 1:

                    if(-1 == x and 0 == y):
                        ans.append('W')
                        break

                    if(1 == x and 0 == y):
                        ans.append('E')
                        break

                    west = ((x + 1) // 2  , y // 2)
                    east = ((x - 1) // 2  , y // 2)

                    if (west[0] + west[1]) % 2 == 1:
                        ans.append('W')
                        x, y = west[0], west[1]
                    else:
                        ans.append('E')
                        x, y = east[0], east[1]
                elif y % 2 == 1:

                    if( 0 == x and 1 == y):
                        ans.append('N')
                        break

                    if(0 == x and -1 == y):
                        ans.append('S')
                        break

                    north = (x // 2 , (y-1) // 2)
                    south = (x // 2 , (y+1) // 2)


                    if (north[0] + north[1]) % 2 == 1:
                        ans.append('N')
                        x, y = north[0], north[1]
                    else:
                        ans.append('S')
                        x, y = south[0], south[1]

            print('Case #{}: {}'.format(tc+1,''.join(ans))) 

main()
