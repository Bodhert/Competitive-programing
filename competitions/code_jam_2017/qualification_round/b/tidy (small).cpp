#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;



int main()
{
  int cases;
  int casesPrint = 0;
  cin >> cases;
  while(cases--)
    {
      bool isTidy = false;
      ull number, ans, temp;
      
      cin >> number;
      
      
      while(!isTidy)
	{
	  if( (number/10) == 0)
	    {
	      ans = number;
	      break;
	    }

	  temp = number;
	  
	  while(true)
	    {
	      if((temp/10) == 0)
		{
		  isTidy = true;
		  ans = number;
		  break;
		}
	      ull actual = temp % 10;
	      ull previous = (temp/10) % 10;
	      if(!(actual >= previous)) break;
	      temp /= 10;
	    }
	  
	  number--;
	  
	}
      
      cout << "Case #"  << ++casesPrint << ": " << ans << endl;
    }
  return 0;
}
