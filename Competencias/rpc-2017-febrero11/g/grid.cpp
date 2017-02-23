#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAXN = 10;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
int input[MAXN][MAXN];
int visited[MAXN][MAXN];

void seting()
{

  for(int i = 0; i < MAXN; ++i)
    {
      for(int j = 0; j < MAXN; ++j)
	{
	  visited[i][j] = input[i][j] = -1;
	}
    }
}

void printMatrix(int m, int n, int (&matrix)[MAXN][MAXN])
{
  for(int i = 0; i < m; ++i )
    {
      for(int j = 0; j < n; ++j)
	{
	  cout << matrix[i][j] << ' ';
	}
      cout << endl;
    }
  cout << endl;
}

void bfs(int i, int j)
{
  ii start = make_pair(i,j);
  visited[i][j] = 0;

  queue<ii> q;
  q.push(start);

  while(!q.empty())
    {
      int I = q.front().first;
      int J = q.front().second;
      int curr = visited[I][J];
      q.pop();

      for(int k = 0; k < 4; ++k)
	{
	  int incrementI = I + (dr[k] * (input[I][J]));
	  int incrementJ = J + (dc[k] * (input[I][J]));

	  //cout << "i: " <<  incrementI << " j: "  <<   incrementJ  << endl;
	  if(visited[incrementI][incrementJ] == -1)
	    {
	      if(input[incrementI][incrementJ] > 0 && ( (incrementI >= 0 && incrementJ >= 0) && (incrementI <= MAXN && incrementJ <= MAXN) )) //el problema esta en que me esa dando posciciones de memoria al azar mayores que 0;
		{
		  visited[incrementI][incrementJ] = curr + input[I][J] ;
		  ii temp = make_pair(incrementI,incrementJ);
		  q.push(temp);
		}
	    }
	  
	}
      
    }
}


int main()
{
  int m,n;  // recordar que estoy utilizando todo indice 0
  cin >> m >> n;
  seting();

  for(int i = 0; i < m; ++i)
    {
      for(int j = 0; j < n; ++j )
	{
	  cin >> input[i][j];
	}
    }
 
  bfs(0,0);

  int ans = visited[m-1][n-1];
  if(ans != -1) cout << ans;
  else cout << "IMPOSSIBLE";

  cout << endl;
  cout << "visited" << endl;
  printMatrix(m,n,visited);

 
}

