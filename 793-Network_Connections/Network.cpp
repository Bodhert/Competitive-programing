using namespace std;
#include <sstream>
#include <bits/stdc++.h>

vector<int> p;

void initialize(int n)
{
  p.clear();
  for(int i = 0; i < n; ++i)
    p.push_back(i);
}

int find(int u)
{
  if(p[u] == u) return u;
  return p[u] = find(p[u]); // analizar bien que hace esta linea
}

void join(int u, int v)
{
  int a = find(u);
  int b = find(v);
  if(a != b) p[a] = b;
}

int main()
{
  int tc,c,c1,c2,y,n;
  string in;
  char command;
  cin >> tc;
  while(tc--)
  {
    y = 0;n = 0;
    // cout << tc + 1 << endl;
    cin >> c; //cout << c << endl;
    initialize(c);
    getline(cin,in);
    while(getline(cin,in) && in.size() != 0)
    {
      istringstream ss(in);
      ss >> command >> c1 >> c2;
      c1--;c2--;
      // cout << command << " " << c1 <<  " " << c2 << endl;
      if(command == 'c') join (c1,c2);
      else
      {
        if(find(c1) == find(c2)) y++;
        else n++;
      }
    }

    if(tc)
    cout << y << ',' << n << endl << endl;
    else
    cout << y << ',' << n << endl;

  }
  return 0;
}
