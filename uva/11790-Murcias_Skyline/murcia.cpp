#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& h, vector<int>& w ){
  int size = h.size();
  int L[size], L_id[size], P[size];

  int lis = 0, lis_end = 0;
  for(int i = 0; i < size; ++i){
    int pos = lower_bound(L, L + lis, h[i]) - L;
    L[pos] = h[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if(pos + 1 > lis){ 
      lis = pos + 1;
      lis_end = i;
    }else if(pos + 1 == lis){
      
       int x = lis_end, sum = 0;
       for(;P[x] >= 0; x = P[x]) sum += w[x];
       sum += w[x];
       
       int x1 = i, sum1 = 0;
       for(;P[x1] >= 0; x1 = P[x1]) sum1 += w[x1];
       sum1 += w[x1];

       if(sum1 > sum){
	 lis = pos + 1;
	 lis_end = i;
       }
    }
  }

  int x = lis_end, sum = 0;
  for(;P[x] >= 0; x = P[x]) sum += w[x];
  sum += w[x];

  return sum;
  
  
}

int LDS(vector<int>& h, vector<int>& w){  // este metodo esta mal formulado 
  int size = h.size();
  int L[size], L_id[size], P[size];

  int lis = 0, lis_end = 0;
  for(int i = 0; i < size; ++i){
    int temp = upper_bound(L, L + lis, h[i]) - L; 
    int pos = temp ? temp - 1: lis; 
    L[pos] = h[i]; 
    L_id[pos] = i; 
    P[i] = pos ? L_id[pos - 1] : -1;
    if(pos + 1 > lis){ 
      lis = pos + 1;
      lis_end = i;
    }else if( pos + 1 == lis){
       // int x = lis_end, sum = 0;
       // for(;P[x] >= 0; x = P[x]) sum += w[x];
       // sum += w[x];
       
       // int x1 = i, sum1 = 0;
       // for(;P[x1] >= 0; x1 = P[x1]) sum1 += w[x1];
       // sum1 += w[x1];

       // if(sum1 > sum){
       // 	 lis = pos + 1;
       // 	 lis_end = i;
       // }
    }
    
  }

  int x = lis_end, sum = 0;
  for(;P[x] >= 0; x = P[x]) sum += w[x];
  sum += w[x];
  
  return sum;
  
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  vector<int> H,W;
  int tc,size,b, cases = 0;
  cin >> tc;
  while(tc--){
    
    cin >> size;
    H.assign(size,0);
    W.assign(size,0);
    for(int i = 0; i < size; ++i){
      cin >> b;
      H[i] = b;
    }
    
    for(int i = 0; i < size; ++i){
      cin >> b;
      W[i] = b;
    }

    int increasing = LIS(H,W);
    int decreasing = LDS(H,W); // esta malo el decreasing 
    if(increasing >= decreasing){
      cout <<"Case " << ++cases << ". " << "Increasing " << "(" << increasing <<
	")" << ". "<< "Decreasing " << "(" << decreasing << ")" << "." << endl;
    }else{
      cout <<"Case " << ++cases << ". " <<  "Decreasing " << "(" << decreasing <<
	")" << ". "  << "Increasing " << "(" << increasing << ")" << "."<<endl;
    }
      
  }
  return 0;
}


/*
  ya logre el criterio de desempate con lis, el que me esta presentando problemas
  es lds;
  con los casos del udebug , el lis me lo esta generando correctamente, el lds no

  */
