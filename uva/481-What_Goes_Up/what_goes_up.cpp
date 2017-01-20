#include <bits/stdc++.h>
using namespace std;

void print(int lis,int end, vector<int>& a, vector<int>& p) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  cout << lis << endl << '-' << endl;
  cout << a[x] << endl;
  for (; !s.empty(); s.pop()) cout << s.top() << endl;
}

int main(){
// #ifndef ONLINE_JUDGE
//   freopen("in", "r", stdin);  // this is for debuging purposes when im using gdb tool
// #endif
  
  vector<int> A,L,L_id,P;
  int number,lis = 0, lis_end = 0;
  while(cin >> number){
    A.push_back(number);
  }
  int size = A.size();
  L.assign(size,0);
  L_id.assign(size,0);
  P.assign(size,0);
  
  for(int i = 0; i < size; ++i){
    vector<int>::iterator low;
    low = lower_bound(L.begin(),L.begin() + lis, A[i]);
    int pos = low - L.begin();
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if(pos + 1 >= lis){
      lis = pos + 1;
      lis_end = i;
    }
  }

  print(lis,lis_end, A, P);

  
  return 0;
}
