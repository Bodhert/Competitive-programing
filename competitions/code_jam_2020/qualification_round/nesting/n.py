# import sys #debugging purposes

def main():
    # sys.stdin = open('in', 'r') 
    for T in range(int(input())):
        s = list(input())
        
        currChar = ''
        i = 0
        while i < len(s):
            if s[i] == '1' and currChar != '(':
                if i == 0:
                    s.insert(0,'(')
                else:
                    s.insert(i, '(')
                currChar='('
                i+1
            elif s[i] == '0' and currChar == '(':
                s.insert(i,')')
                currChar = ''
                i+=1
            # print(len(s))
            i += 1

            if s[-1] == '1':
                s.append(')')
        print('Case #{0}: {1}'.format(T+1,''.join(s)))



main()
