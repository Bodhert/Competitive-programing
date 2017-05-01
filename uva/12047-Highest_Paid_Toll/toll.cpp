#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int INF = 1000000000;

typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;



vector<ii> road[MAXN];
vector<ii> reversedRoad[MAXN];
int  distRoad[MAXN];
int distReversedRoad[MAXN];



void printD(int n)
{
  cout << "road" << endl;
  for(int i = 0; i < n; ++i)
    {
      cout << i  << ":" << distRoad[i] << " "; 
    }

  cout << endl;
  cout << "reversed" << endl;
  for(int i = 0; i < n; ++i)
    {
      cout << i << ":" << distReversedRoad[i] << " ";
    }

  cout << endl;
  
}



void clean()
{
  for(int i = 0; i < MAXN; ++i)
    {
      road[i].clear();
      reversedRoad[i].clear();
      distRoad[i] = distReversedRoad[i] = INF;
    }
}





void dijkstraReverseRoad(int source)
{
  distReversedRoad[source] = 0;
  priority_queue<ii, vector<ii>,greater<ii> > pq; pq.push(ii(0,source));
  while(!pq.empty())
    {
      ii front = pq.top(); pq.pop();
      int distance = front.first, cur = front.second;
      if(distance > distReversedRoad[cur] ) continue;
      for(int i = 0; i < reversedRoad[cur].size(); ++i)
	{
	  int next = reversedRoad[cur][i].first;
	  int nextDistance = reversedRoad[cur][i].second;
	  
	  if(distReversedRoad[cur] + nextDistance < distReversedRoad[next])
	    {
	      distReversedRoad[next] = distReversedRoad[cur] + nextDistance;
	      pq.push(ii(distReversedRoad[next],next));
	    }
	}
    }
}


void dijkstraRoad(int source)
{
  distRoad[source] = 0;
  priority_queue<ii, vector<ii>,greater<ii> > pq; pq.push(ii(0,source));
  while(!pq.empty())
    {
      ii front = pq.top(); pq.pop();
      int distance = front.first, cur = front.second;
      if(distance > distRoad[cur] ) continue;
      for(int i = 0; i < road[cur].size(); ++i)
	{
	  int next = road[cur][i].first;
	  int nextDistance = road[cur][i].second;
	  
	  if(distRoad[cur] + nextDistance < distRoad[next])
	    {
	      distRoad[next] = distRoad[cur] + nextDistance;
	      pq.push(ii(distRoad[next],next));
	    }
	}
    }
}

int solve(int nodes, int money)
{
  int ans = -1;
  for(int i = 0; i < nodes; ++i)
    {
      for(int j = 0; j < road[i].size();++j)
	{
	  int node = road[i][j].first;
	  int nodeCost = road[i][j].second;
	  if(distRoad[i]!=INF && distReversedRoad[node]!=INF)
	    {
	      int cost = money - (nodeCost + distRoad[i] + distReversedRoad[node]) ;
	      if(cost >= 0) ans = max(ans,nodeCost);
	    }
	}
    }
  return ans;
}

int main()
{
  //freopen("inUdebug","r",stdin); // debug purposes
  
  int testCases,nodes,roads,money,start,destination,city1,city2,weigth;
  cin >> testCases;
  while(testCases--)
    {
      clean();
      cin >> nodes >> roads >> start >>  destination >> money;
      start--; destination--;
      for(int i = 0; i < roads; ++i)
	{
	  cin >> city1 >> city2 >> weigth;
	  city1--;city2--;
	  road[city1].push_back(ii(city2,weigth));
	  reversedRoad[city2].push_back(ii(city1,weigth));
	}
      
      dijkstraRoad(start);
      dijkstraReverseRoad(destination);
      // printD(nodes);
      int ans = solve(nodes,money);
      cout << ans << endl;      
    }
  
  return 0;
}
