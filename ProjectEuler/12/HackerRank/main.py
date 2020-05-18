import math

MAXN = 100000

def build_sieve():
    prime = [True] * MAXN
    p = 2
    while (p * p <= MAXN): 
        if (prime[p] == True):  
            for i in range(p * p, MAXN, p): 
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False
    primes = []
    for p in range(MAXN): 
        if prime[p]: 
            primes.append(p)
    return primes

def main():
    primes = build_sieve()
    # print(primes)
    for _ in range(int(input())):
        N = int(input())
        divisors = 1
        curr_num = 1
        triangular_number = 1
        while divisors <= N:
            divisors = 1
            curr_num += 1
            triangular_number += curr_num 
            temp_triangular = triangular_number
            for prime in primes:
                if prime * prime > temp_triangular:
                    divisors *= 2
                    break
                
                exponent = 1
                while temp_triangular % prime == 0:
                    exponent += 1
                    temp_triangular //= prime
                if exponent > 1:
                    divisors *= exponent
                if temp_triangular == 1:
                    break

        print(triangular_number)


main()
