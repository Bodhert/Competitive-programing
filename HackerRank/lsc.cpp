#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

vector <int> a;
vector <int> b;
int mem[1005][1005];



void printMat(int n, int m){
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j)
      cout << mem[i][j] << " ";
    cout << endl;
  }

}

void printVect(int n, int m){
  for(int i = 0; i < n ; ++i) cout << a[i];
  cout << endl;
  for(int i = 0; i < m ; ++i) cout << b[i];

}

int lcs(int n, int m){
  int maxi = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(a[i-1] == b[j-1]) mem[i][j] = mem[i-1][j-1] + 1;
      else mem[i][j] = max(mem[i-1][j],mem[i][j-1]);
      if(mem[i][j] > maxi) maxi = mem[i][j];
    }
  }
  return maxi;
}


void prinPath(int n , int m, int max){
  int i = n; int j = m; int index = max;
  vector <int> path (max);
  while(i > 0 && j > 0){
    if(a[i-1] == b[j-1]){
      path[index-1] = a[i-1];
      //cout << a[i-1] << " == " << b[j-1] << endl;
      index--; j--; i--;
    }else if(mem[i-1][j] > mem[i][j-1]) i--;
    else j--;
  }

  for(int k = 0;  k < max-1; ++k) cout << path[k] << " "; // es posible que me cause problemas de presentacion
  cout << path[max-1];
}


int main() {
  int m,n,Na,Ma;
  cin >> n >> m;
  for(int i = 0; i < n ; ++i){
    cin >> Na;
    a.push_back(Na);
  }
  for(int i = 0; i < m ; ++i){
    cin >> Ma;
    b.push_back(Ma);
  }

  memset(mem,0,sizeof mem);
  int max = lcs(n,m);
  //cout << max << endl;
  //cout << n << " " << m << endl;
  prinPath(n,m,max);
  cout << endl;
  //printMat(n,m);

  return 0;
}
