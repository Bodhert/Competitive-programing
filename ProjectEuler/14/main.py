MAXN = 1000000

def calculate_collatz(hash, num):
    if num in hash:
        return hash[num]
    else:
        next = num // 2 if num % 2 == 0 else (num*3+1)
        # print(next)
        hash[num] = 1 + calculate_collatz(hash, next)
        return hash[num]

def main():
    hash = {1:1}
    maxi = -1
    num = -1
    for i in range(2, MAXN+4):
        calculate_collatz(hash, i)
        if hash[i] > maxi:
            maxi = hash[i]
            num = i 
    print(num, maxi)
main()
