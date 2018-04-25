#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
bool sieve[MAXN];
vector<int> primes;

void build_sieve()
{
    memset(sieve,false,sizeof(sieve));
    sieve[0] = sieve[1] = true;
    for(int i = 2; i*i <= MAXN; ++i)
    {
        if(!sieve[i])
        {
            for(int j = i*i; j <= MAXN; j+=i)
            {
                sieve[j] = true;
            }
        }
    }

    for(int i = 2; i <= MAXN; ++i)
    {
        if(!sieve[i]) primes.push_back(i);
    }
}

int main()
{
    build_sieve();
    cout << " sieve size = " << primes.size() << "  " <<  primes[10000] << endl;
} 