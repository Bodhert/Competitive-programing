#include <bits/stdc++.h>
using namespace std;

int main()
{
  int cases, flips,  pcases = 0;
  string row;
  cin >> cases;
  while(cases--)
    {
      cin >> row >> flips;
      int worstCase = row.size();
      int moves = 0;
      int rowSize = row.size();
      int i = 0;

      
      while(i <= worstCase)
	{
	  if(row[i] == '-')
	    {
	      if(i + flips <= rowSize)
		{
		  for(int j = i; j < (i + flips); ++j)
		    {
		      if(row[j] == '-') row[j] = '+';
		      else row[j] = '-';
		    }
		  i = 0;
		  ++moves;
		}
	    }
	   ++i;
	}

      int decision = count(row.begin(),row.end(),'+');

      if(!(decision == rowSize))  cout << "Case #"  << ++pcases << ": " << "IMPOSSIBLE" << endl;
      else
	{
	    cout << "Case #"  << ++pcases << ": " << moves << endl;
	}

      
    }
  
  return 0;
}
