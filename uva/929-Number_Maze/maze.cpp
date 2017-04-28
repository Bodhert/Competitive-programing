#include <bits/stdc++.h>

using namespace std;

#define INF  1000000000

const int MAXN = 2000;
typedef pair<int,int> ii;
typedef pair<int,ii > ipii;

int maze[MAXN][MAXN];
int dist[MAXN][MAXN];
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};


void printDist()
{
   for(int i = 0; i < MAXN; ++i)
    {
      for(int j = 0; j < MAXN; ++j)
	{
	  cout << dist[i][j] << " ";
	}
      cout << endl;
    }
   cout << endl;
}

void printMaze()
{
   for(int i = 0; i < MAXN; ++i)
    {
      for(int j = 0; j < MAXN; ++j)
	{
	  cout << maze[i][j] << " ";
	}
      cout << endl;
    }
   cout << endl;
}

void clean()
{
  for(int i = 0; i < MAXN; ++i)
    {
      for(int j = 0; j < MAXN; ++j)
	{
	  maze[i][j] = -1;
	  dist[i][j] = INF; 
	}
    }
}

bool isInRange(int i, int j)
{
  if((i >= 0 && j >= 0) && (i < MAXN && j < MAXN)) 
    if(maze[i][j] != -1) return true;
  return false;
}

void dijkstra(int row, int column)
{
  dist[0][0] = maze[0][0];
  priority_queue< ipii, vector<ipii>, greater<ipii> > pq;
  pq.push(ipii(0,ii(0,0)));
  while(!pq.empty())
    {
      ipii front = pq.top(); pq.pop();
      int d = front.first;
      ii u = front.second;
      int i = u.first;
      int j = u.second;
      if(d > dist[i][j]) continue;
      for(int k = 0; k < 4; ++k)
	{
	  int i1 = i + dr[k];
	  int j1 = j + dc[k];
	  if(isInRange(i1,j1))
	    {
	      if(dist[i][j] + maze[i1][j1] < dist[i1][j1])
		{
		  
		  dist[i1][j1] = dist[i][j] + maze[i1][j1];
		  if(i1 == row-1 && j1 == column-1) break;
		  pq.push(ipii(dist[i1][j1], ii(i1,j1)));
		}
	    }
	}
    }
  
  
}

int main()
{
  //freopen("in","r",stdin); // debug purposes
  
  int testCases,rows,colums,num;
  cin >> testCases;
  while(testCases--)
    {
      clean();
      cin >> rows >> colums;
      for(int i = 0; i < rows; ++i)
	{
	  for(int j = 0; j < colums; ++j)
	    {
	      cin >> num;
	      maze[i][j] = num;
	    }
	}
      
      // printMaze();
      dijkstra(rows,colums);
      cout << dist[rows-1][colums-1] << endl;
      //printDist();
    }
  return 0;
}
