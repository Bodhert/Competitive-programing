# import sys #debugging purposes

def main():
    # sys.stdin = open('in', 'r') 
    for T in range(int(input())):
        s = list(map(int,input()))
        ans = []
        s.insert(0,0)
        s.append(0)
        i = 0
        while i < len(s)-1:
            ans.append(str(s[i]))
            diff = s[i+1] - s[i] 
            if diff > 0:
                ans.append('(' * diff )
            elif diff < 0:
                ans.append(')' * abs(diff))
            i +=1

        print('Case #{0}: {1}'.format(T+1,''.join(ans[1::])))

main()
