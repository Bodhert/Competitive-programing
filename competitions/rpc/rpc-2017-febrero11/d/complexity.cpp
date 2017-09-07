#include<bits/stdc++.h>

using namespace std;

int main()
{
  map<char, int> letters; 
  string in;
  cin >> in;
  
  for(int i = 0; i < in.size();++i)
    {
      letters[in[i]] += 1;
    }
   
  int count = 0;
  int tempSize = in.size() - 1;
  while(letters.size() > 2)
    {
      int minimum = 200;
      char indexMinimum = ' ';
      for(int i = 0; i < in.size(); ++i)
	{
	  if(letters.count(in[i]))
	    {
	      if(letters[in[i]] < minimum)
		{
		  indexMinimum = in[i];
		  minimum = letters[in[i]];
		}
	    }
	  
	}
      
      if(indexMinimum != ' ')
	{
	  count += letters[indexMinimum];
	  letters.erase(indexMinimum);
	}
      
      // cout << letters.size() << endl;
      
      
    }
  
  
  cout << count ;
  
  return 0;
}
