#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> polygonSides;
    int sides;
    double L;

    cin >> sides;
    while(sides--)
    {
        cin >> L;
        polygonSides.push_back(L);
    }

    sort(polygonSides.begin(), polygonSides.end(),greater<double>());

    double condition = 0;
    for(int i = 1; i <= polygonSides.size(); ++i)
    {
        condition += polygonSides[i];
    }

    if(polygonSides[0] < condition)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}