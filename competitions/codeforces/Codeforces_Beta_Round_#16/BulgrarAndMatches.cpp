#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    // freopen("in","r",stdin);
    vii warehouse;
    int ruckSackSize, containers, matchBoxSize, numOfMatches, ans = 0;

    cin >> ruckSackSize >> containers;

    while (containers--)
    {
        cin >> matchBoxSize >> numOfMatches;
        warehouse.push_back(make_pair(numOfMatches, matchBoxSize));
    }

    sort(warehouse.begin(), warehouse.end(), greater<ii>());

    for (int i = 0; i < warehouse.size() && ruckSackSize; i++)
    {
        ii temp = warehouse[i];
        int tempMatches = temp.first;
        int tempMatchboxSize = temp.second;
        if (tempMatchboxSize <= ruckSackSize)
        {
            ruckSackSize -= tempMatchboxSize;
            ans += (tempMatches * tempMatchboxSize);
        }
        else
        {
            ans += (ruckSackSize * tempMatches);
            ruckSackSize = 0;
        }
    }

    cout << ans << endl;

    return 0;
}