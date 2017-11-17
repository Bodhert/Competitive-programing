/*
ID: alejand24
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;


using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string commet, group;
    
    fin >> commet >> group;

    unsigned long long numComet = 1,numGroup = 1;

    for(int i = 0; i < commet.size(); ++i)
    {
      numComet *= (commet[i] - 'A') + 1;
    }

    for(int i = 0; i < group.size(); ++i)
    {
      numGroup *= (group[i] - 'A') + 1;
    }

    if((numGroup % 47) == (numComet % 47)) fout << "GO" << endl;
    else fout << "STAY" << endl;
  
    return 0;
}

