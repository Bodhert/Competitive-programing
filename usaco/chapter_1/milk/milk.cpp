/*
ID: alejand24
TASK: milk
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);

    vii milks;
    int milkWanted,numberFarmers,price,quantity, totalPrice = 0;
    cin >> milkWanted >> numberFarmers;
    for(int i = 0; i < numberFarmers; ++i)
    {
        cin >> price >> quantity;
        milks.push_back(ii(price,quantity));
    }

    sort(milks.begin(), milks.begin() + numberFarmers);

    for(int i = 0; i < milks.size() && milkWanted != 0; ++i)
    {
        int curPrice = milks[i].first;
        int curUnits = milks[i].second;
        if(curUnits <= milkWanted)
        {
            milkWanted -= curUnits;
            totalPrice += curUnits*curPrice;
        }
        else
        {
            totalPrice += milkWanted*curPrice;
            break;
        }
    }

    cout << totalPrice << endl;



    return 0;
}

