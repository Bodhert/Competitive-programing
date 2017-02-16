#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> btset;
vi primes;

void sieve(ll upperbound)
{
  _sieve_size = upperbound + 1;
  btset.set();
  btset[0] = btset[1] = 0;
  for(ll i = 0; i < _sieve_size; i++)
    {
      if(btset[i])
	{
	  for(ll j = i*i; j < _sieve_size; j+=i) btset[j] = 0;
	  primes.push_back(i);
	}
    }
}


bool isPrime(ll N)
{
  if(N <= _sieve_size) return btset[N];
  for(int i = 0; i < primes.size(); i++)
    if(N % primes[i] == 0 ) return false;
  return true;
			      
}

bool isLeft()
{
  
}

bool isRigth()
{
  
}

int main()
{
  sieve(80000000);
  return 0;
}
