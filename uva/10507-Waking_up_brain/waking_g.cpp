using namespace std;
#include <bits/stdc++.h>

const int MAXN = 30;
map<char,int> id;
vector <int> adjlist[MAXN];
int contador[MAXN];
bool visited[MAXN];

void printGraph(int n)
{
  for(int i = 0; i < n; ++i)
  {
    cout << " el nodo " << i << " va a: ";
    for(int j = 0; j < adjlist[i].size();++j)
    {
      cout  << adjlist[i][j] << " ";
    }
    cout << endl;
  }
}

void assignId(char letter,int index)
{
   id[letter] = index;
}

bool exists(char letter)
{
  if(id.count(letter) > 0) return true;
  return false;
}

void clean()
{
  id.clear();
  for(int i = 0; i < MAXN; ++i)
  {
    contador[i] = 0;
    adjlist[i].clear();
    visited[i] = false;
  }
}

void printV(int n)
{
  for(int i = 0; i < n; ++i) cout << contador[i] << " ";
  cout << endl;
}

int bfs()
{
  queue <int> q;
  int year = 0;
  q.push(0); q.push(1); q.push(2);
  visited[0] = true; visited[1] = true; visited[2] = true;
  // contador[0] = 3; contador[1] = 3; contador[2] = 3;
  while(!q.empty())
  {
    bool pushed = false;
    int cur  = q.front();
    q.pop();
    for(int i = 0; i < adjlist[cur].size(); ++i)
    {
      int next = adjlist[cur][i];
      if(contador[next] < 3 && !visited[next]) contador[next]++;
      if(contador[next] >= 3 && !visited[next])
      {
        visited[next] = true;
        q.push(next);
        pushed = true;
      }
    }

    if(pushed)year++;  // si pusheo algo nuevo a la cola aumento el año,
  }
  return year;
}

int main()
{
  int n,m,index;
  char inc1,inc2,in1,in2,in3;
  while(cin >> n)
  {
    clean();
    cin >> m;
    cin >> in1 >> in2 >> in3;
    // cout << n << " " << m << endl << in1 << in2 << in3 << endl;
    assignId(in1,0);  assignId(in2,1); assignId(in3,2);
    index = 3;
    for(int i = 0; i < m; ++i)
    {
      cin >> inc1 >> inc2;
      if(!exists(inc1)) assignId(inc1,index++);
      if(!exists(inc2)) assignId(inc2,index++);
      adjlist[id[inc1]].push_back(id[inc2]); // se cambia por el push en ambas direcciones;
      adjlist[id[inc2]].push_back(id[inc1]);
    }

    // printGraph(n);
    // printV(n);
    int year = bfs();
    // printV(n);
    // cout << year << endl;
    //
    if(n == 3) cout << "WAKE UP IN, " << "0" << ", YEARS" << endl;
    else
    {
      for(int i = 3; i < n; ++i) //que pasa si solo me pasan 3
      {
        if(contador[i] < 3 ) { cout << "THIS BRAIN NEVER WAKES UP" << endl; break;}
        else { cout << "WAKE UP IN, " << year << ", YEARS" << endl; break;}
      }
    }


  }

  return 0;
}
