#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000;
bool sieve[MAXN+5];
vector <int> primes;

vector <long long> factorization(long long a)
{
    vector <long long> ans;
    long long b = a;
    for(int i = 0; 1LL * primes[i] * primes[i] <= a; ++i)
    {
        int p = primes[i];
        while(b % p == 0)
        {
            ans.push_back(p);
            b /= p;
        }
    }

    if(b != 1) ans.push_back(b);
    return ans;
}

void build_sieve()
{
    memset(sieve,false,sizeof(sieve));
    sieve[0] = sieve[1] = true;
    for(int i = 2; i * i <= MAXN; ++i)
    {
        if(!sieve[i])
            for(int j = i * i; j <= MAXN; j+= i) sieve[j] = true;
    }

    for(int i = 2; i <= MAXN; ++i)
        if(!sieve[i]) primes.push_back(i);
}

int main()
{
    build_sieve();
    vector<long long> ans = factorization(600851475143);
    cout << ans[ans.size()-1] << endl;
    return 0;
}

