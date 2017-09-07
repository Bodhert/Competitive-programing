#include <bits/stdc++.h>
using namespace std;


int main()
{   
    //freopen("in4", "r" , stdin);
    long double x, y, z;
    cin >> x >> y >> z;
    long double div = z - y;
    int pages = (int)(x / div);
    int realSpace = (log10(pages));
    realSpace += 1;
    realSpace *= 2;
    realSpace += 1;    
    int realSpace1 = div - realSpace;
    long double ans = x/realSpace1;
    cout << ceil(ans) << endl;

    return 0;
}