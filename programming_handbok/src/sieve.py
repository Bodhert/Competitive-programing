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
