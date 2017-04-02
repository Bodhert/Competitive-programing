#include <bits/stdc++.h>
using namespace std;

#define isOn(S, j) (S & (1 << j))

int main()
{
  int peonoland;
  complex<double> gaussian(-1,1);
  while(cin >> peonoland)
    {
      complex<double> ans(0,0);
      for(int j = 0; j <= 29; ++j)
	{
	  if(isOn(peonoland,j))
	    {
	      ans += pow(gaussian,j);
	    }
	}
      
      cout << ans.real() << " " << ans.imag() << endl;
     
    }
  
  return 0;
}
