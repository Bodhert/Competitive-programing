#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1<<15) + 5;
int Ncube[MAXN];


bool isNeighbour(int i, int j)
{
  if(i == j) return false;
  int neighbour = (i^=j);
  return !(neighbour & (neighbour-1));
    
}

void setContainers()
{
  for(int i = 0; i < MAXN; ++i)  Ncube[i] = 0;
}

int main()
{
  int dimension,corners,corner_weigth;
  while(cin >> dimension)
    {
      setContainers();
      corners = 1<<dimension;
      for(int i = 0; i < corners; ++i)
	{
	  cin >> corner_weigth;
	   for(int j = 0; j < corners; ++j)
	    {
	      if(isNeighbour(i,j) &&  i!= j)
		{
		  Ncube[j] += corner_weigth;
		}
	    }
	}

      int maxi = -1;
     
      for(int i = 0; i < corners; ++i)
	{
	  for(int j = 0; j < corners; ++j)
	    {
	      if(isNeighbour(i,j) && i!=j)
		{
		  int tempSum = Ncube[i] + Ncube[j];
		  maxi = max(maxi,tempSum);
		}
	    }
	}
  
      cout << maxi << endl;
    }
  
  return 0;
}
