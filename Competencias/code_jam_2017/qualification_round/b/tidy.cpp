#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull findingRest(ull number, ull iteration)
{
  ull ans = 0;
  for(ull i = 0; i <= iteration; ++i)
    {
      ull actual = number%10;
      ans += actual * pow(10,i);
      number /= 10;
    }
  return ans;
}

int main()
{
  int cases;
  int casesPrint = 0;
  cin >> cases;
  while(cases--)
    {
      bool isTidy = false;
      ull number, ans, temp, restFactor;
      
      cin >> number;
      
      
      while(!isTidy)
	{
	  if( (number/10) == 0)
	    {
	      ans = number;
	      break;
	    }

	  restFactor = 1;
	  temp = number;
	  ull iteration = 0;
	  
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
	      if(!(actual >= previous))
		{
		  if(actual != 0)
		    {
		      restFactor = findingRest(number,iteration);
		    }
		  break;
		  
		}
	      
	      iteration++;
	      temp /= 10;
	    }
	  
	  number -= restFactor;
	  
	}
      
      cout << "Case #"  << ++casesPrint << ": " << ans << endl;
    }
  return 0;
}
