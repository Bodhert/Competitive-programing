#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<74000000> btset;
vi primes;

void sieve(ll upperbound)
{
  _sieve_size = upperbound + 1;
  btset.set();
  btset[0] = btset[1] = 0;
  for(ll i = 2; i <= _sieve_size; i++)
    {
      if(btset[i])
	{
	  for(ll j = i * i; j <= _sieve_size; j += i) btset[j] = 0;
	  primes.push_back((int)i);
	}
    }
}


bool isPrime(ll N)
{
  if(N <= _sieve_size) return btset[N];
  for(int i = 0; i < (int)primes.size(); i++)
    if(N % primes[i] == 0 ) return false;
  return true;
			      
}

bool isLeft(ll Number)
{
  while(Number / 10 != 0 )
    {
      ll digits = log10(Number);
      ll power = pow(10,digits);
      Number %= power;
      if(!isPrime(Number)) return false;
    }
  return true;
}
 
bool isRigth(ll Number)
{
  while(Number / 10 != 0)
    {
      Number /= 10;
      if(!isPrime(Number)) return false;
    }
  
  return true;
}

int main()
{
  sieve(74000000);
  ll count = 0;
  for(ll i = 8; i <= primes.size(); i++)
    {
      if(isRigth(primes[i]) &&  isLeft(primes[i])) count += primes[i];
    }

  cout << count << endl;
  
  return 0;
}
