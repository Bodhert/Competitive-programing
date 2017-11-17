/*
ID: alejand24
TASK: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;


using namespace std;

vector<string> names;
map<string,int> acount;

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    int people, money, toGive; string name, reciver;
    cin >> people;

    for(int i = 0; i < people; ++i)
    {
        cin >> name;
        names.push_back(name);
        acount[name] = 0;
    }

    for(int i = 0; i < people; ++i)
    {
     cin >> name;
     cin >> money >> toGive;
     int tempMoney;
     if(toGive != 0) tempMoney = money/toGive;
     for(int j = 0; j < toGive; ++j)
     {
      cin >> reciver;
      acount[reciver] += tempMoney;
     }
     int left = money - (tempMoney*toGive);
     acount[name] -= (money-left);
    }

    for(int i = 0; i < people; ++i)
    {
        cout << names[i] << " " << acount[names[i]] << endl;
    }


    return 0;
}
