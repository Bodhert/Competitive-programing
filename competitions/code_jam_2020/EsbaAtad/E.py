import sys

def reverse(b):
    return(b[::-1])

def complement(b):
    ans=[]
    for bit in b:
        if bit == '1':
            ans.append('0')
        else:
            ans.append('1')
    return ans

def both(b):
    return (reverse(complement(b)))

def main():
    tc, b_size = map(int, input().split(' '))
    for _ in range(tc):
        b = []
        for i in range(1, b_size+1, 10):
            group = []
            for j in range(1,11):
                print(j)
                sys.stdout.flush()
                bit = input()
                group.append(bit)
                i += 1
            b.append(group)
            print(complement(b[0]))

            print(i)
main()
