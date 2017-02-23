#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

vector < vector<int> > adjlist;
vector <int> dfs_num;
//int visited[30];


void dfs(int u){
  dfs_num[u] = 1;
  for(int i = 0; i < adjlist[u].size(); i++){
    int v = adjlist[u][i];
    //cout << "int v == " << v << endl;
    if(dfs_num[v] == -1){
      //cout << "lista de adjacencia " <<  adjlist[u][i] << endl;
      dfs(v);
    }
    // return;
  }
}

int main(){
  int T;
  string max,in1,in2;
  string in;
  char s[3];
  bool bandera = false;

  cin >> T;
  //scanf("\n");
  
  while(T--){
    
    cin >> max ;
    //cout << max << endl;

    adjlist.assign(max[0] - 64, vector <int> ());
    dfs_num.assign(max[0] - 64, - 1);
    int maxN = max[0] - 'A'; // - 64
    getline(cin,in);
    
    while(getline(cin,in)){
      if(in.size() == 0) break;
      int pos1 = in[0] - 'A';
      //cout << in << endl;
      int pos2 = in[1] - 'A';
      // cout << pos1 << " " << pos2 << endl;
      adjlist[pos1].push_back(pos2);
      adjlist[pos2].push_back(pos1);
    }

    int cont = 0;
    for(int i = 0; i < dfs_num.size(); i++){
      if(dfs_num[i] == -1)
	++cont; 	dfs(i);
    }
    
    if(!bandera) bandera = true;
    else cout << endl;
    cout << cont << endl;
    
  }
  return 0;
}
