ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll primes;                                      // compact list of primes



void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set(); bs[0] = bs[1] = 0;                   // all 1s except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);                         // add prime i to the list
  }
}
