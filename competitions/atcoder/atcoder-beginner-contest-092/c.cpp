#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005; //1000005; change
int xAxis[MAXN];
int diffs[MAXN];


int main()
{
    //freopen("in","r",stdin); // uncomment for e-z testing

    int Npoints, partial_value = 0;

    cin >> Npoints;

    for(int i = 1; i <= Npoints; ++i)
    {
        int value;
        cin >> value;
        xAxis[i] = value;
    }

    for(int i=1; i<Npoints;++i)
    {
        diffs[i-1] =  abs(xAxis[i]-xAxis[i+1]);
        partial_value += abs(xAxis[i]-xAxis[i+1]);
    }



    for(int i = 1; i <= Npoints; i++)
    {
        int ans = partial_value;

        if(i != 1 && i != Npoints)
        {
            ans -= diffs[i-2];
            ans -= diffs[i-1];

            ans += abs(xAxis[i-1] - xAxis[i+1]);
            ans += abs(xAxis[1]);
            ans += abs(xAxis[Npoints]);
            cout << ans << endl;
        }
        else
        {
            if(i == 1)
            {
                ans -= diffs[0];
                ans += abs(xAxis[i+1]);
                ans += abs(xAxis[Npoints]);
                cout << ans << endl;
            }
            else if ( i == Npoints)
            {
                ans -= diffs[i-2];
                ans += abs(xAxis[i-1]);
                ans += abs(xAxis[1]);
                cout << ans << endl;
            }
        }
    }


}

