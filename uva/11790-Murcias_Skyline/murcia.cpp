#include<bits/stdc++.h>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  vector<int> H,W,ascendingWidth,descendingWidth;
  int tc,size,b, cases = 0;
  cin >> tc;
  while(tc--)
    {
    
      cin >> size;
      H.assign(size,0);
      W.assign(size,0);
      ascendingWidth.assign(size,0);
      descendingWidth.assign(size,0);
      
      for(int i = 0; i < size; ++i)
	cin >> H[i];
      
      
      for(int i = 0; i < size; ++i)
	cin >> W[i];
      
      int ascending = 0, descending = 0;
      
      for(int i = 0; i < size; ++i)
	{
	  int & currentAscending = ascendingWidth[i];
	  int & currentDescending = descendingWidth[i];
	  for(int j = 0; j < i; ++j)
	    {
	      if(H[j] < H[i] && currentAscending < ascendingWidth[j])
		currentAscending = ascendingWidth[j];

	      if(H[j] > H[i] && currentDescending < descendingWidth[j])
		currentDescending = descendingWidth[j];
	    }

	  currentAscending += W[i];
	  currentDescending += W[i];

	  if(ascending < currentAscending)
	    ascending = currentAscending;
	  if(descending < currentDescending)
	    descending = currentDescending;
	}
      
      if(ascending >= descending)
	
	cout <<"Case " << ++cases << ". " << "Increasing " << "(" << ascending <<
	  ")" << ". "<< "Decreasing " << "(" << descending << ")" << "." << endl;
      
      else
       
	cout <<"Case " << ++cases << ". " <<  "Decreasing " << "(" << descending <<
	  ")" << ". "  << "Increasing " << "(" << ascending << ")" << "."<< endl;
      
      
    }
  
  return 0;
}


/*
  this is not my solution , is based on https://github.com/Diusrex/UVA-Solutions/blob/master/11790%20Murcia's%20Skyline.cpp
  because i have been strugling with this problem , Disurex, has the most beautiful code I have ever seen
*/
