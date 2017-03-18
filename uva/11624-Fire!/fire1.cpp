#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define INF 100000000

const int MAXN = 1005;
char matF[MAXN][MAXN];
char matJ[MAXN][MAXN];
int memF[MAXN][MAXN];
int memJ[MAXN][MAXN];
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
// mejorar las preguntas con los arreglos de -1,1,0....
// pueden haber fires desde diferentes  puntos, lanzarlo desde estos puntos
// diferentes
void clear(){
  for(int i = 0; i < MAXN; ++i){
    for(int j = 0; j < MAXN; ++j){
      matF[i][j] = '-';
      matJ[i][j] = '-';
      memF[i][j] = INF;
      memJ[i][j] = INF;
    }
  }
}

void printMF(int k, int m){
  for(int i = 0; i < k; ++i){
    for(int j = 0; j < m; ++j){
      //cout << matF[i][j] << " ";
      cout << memF[i][j] << " ";
    }
    cout << endl;
  }
}



void printMJ(int k, int m){
  for(int i = 0; i < k; ++i){
    for(int j = 0; j < m; ++j){
      //cout << matJ[i][j] << " ";
      cout << memJ[i][j] << " ";
    }
    cout << endl;
  }
}


void bfsF(int i, int j){

  ii s = make_pair(i,j);
  memF[i][j] = 0;

  queue<ii> q;
  q.push(s);

  while(!q.empty()){

    int i = q.front().first;
    int j = q.front().second;
    int curr = memF[i][j];
    q.pop();

    for(int k = 0; k < 4; ++k){
      if(matF[i+dr[k]][j+dc[k]] == '.' || matF[i+dr[k]][j+dc[k]] == 'J'){
        matF[i+dr[k]][j+dc[k]] = 'F';
        if(curr+1 < memF[i+dr[k]][j+dc[k]]) {
          memF[i+dr[k]][j+dc[k]] = curr+1;
          ii temp = make_pair(i+dr[k],j+dc[k]);
          q.push(temp);
        }
      }
    }
  }
}

void bfsJ(int i, int j){
  ii s = make_pair(i,j);
  memJ[i][j] = 0;

  queue<ii> q;
  q.push(s);
  while(!q.empty()){
    int i = q.front().first;
    int j = q.front().second;
    int curr = memJ[i][j];
    q.pop();

    for(int k = 0; k < 4; ++k){
      if(matJ[i+dr[k]][j+dc[k]] == '.' || matJ[i+dr[k]][j+dc[k]] == 'F'){
        matJ[i+dr[k]][j+dc[k]] = 'J';
        if(curr+1 < memJ[i+dr[k]][j+dc[k]]){
          memJ[i+dr[k]][j+dc[k]] = curr+1;
          ii temp = make_pair(i+dr[k],j+dc[k]);
          q.push(temp);
        }
      }
    }
  }
}

int main(){
  int r,c,tc;
  cin >> tc;


  while(tc--){
    vector <ii> fires; // tirarlo desde cada fuego


    cin >> r >> c;
    clear();
    ii temF , temJ;

    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j){
        char temp;
        cin >> temp;
        matF[i][j] = temp;
        matJ[i][j] = temp;
        if(matF[i][j] == 'F'){
          temF = make_pair(i,j);
          fires.push_back(temF);
        }
        if(matJ[i][j] == 'J') temJ = make_pair(i,j);
      }

    }

    for( vector <ii>::const_iterator it = fires.begin() ; it != fires.end(); ++it ){
      bfsF(it->first,it->second);
    }

    bfsJ(temJ.first,temJ.second);

    int mini = INF;

    for(int j = 0; j < c; ++j ){
      if(memJ[0][j] < memF[0][j] && matF[0][j] != '#' ) mini = min(mini, memJ[0][j]);
      if(memJ[r-1][j] < memF[r-1][j] && matF[r-1][j] != '#') mini = min(mini, memJ[r-1][j]);
    }

    for(int i = 0; i < r; ++i){
      if(memJ[i][0] < memF[i][0] && matF[i][0] != '#' ) mini = min(mini,memJ[i][0]);
      if(memJ[i][c-1] < memF[i][c-1] && matF[i][c-1] != '#') mini = min(mini,memJ[i][c-1]);
    }

    if(mini != INF ) cout << mini+1 << endl;
    else cout << "IMPOSSIBLE" << endl;


    //  printMJ(r,c);
    //  cout << endl;
    //  printMF(r,c);
    //  cout << endl << endl;

  }
  return 0;
}
