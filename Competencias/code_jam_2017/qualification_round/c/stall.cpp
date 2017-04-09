#include <bits/stdc++.h>
using namespace std;

int main()
{
  
  int cases, stalls, people;
  cin >> cases;
  while(cases--)
    {
      // setear el contenedor a el valor preestablecido
      cin >> stalls >> people;
      stalls++;
      
      bitset<stalls> simu;
      int leftmost = 0;
      int rigthmost = stalls;
      int mid = stalls/2;
      
      simu.reset();
      simu[0] = simu[stalls] = 1;
      simu[mid] = 1;
      
      for(int i = 0; i < people; ++i)
	{
	  if((mid - leftmost) >=  (rigthmost - mid))
	    {
	      mid = (mid - leftmost) / 2;
	      
	    }
	}
      
      if(stall )
      
      
    }
  
  return 0;
}
