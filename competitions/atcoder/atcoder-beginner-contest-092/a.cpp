#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d , min_bus, min_train;

    cin >> a >> b >> c >> d;

    min_train = min(a,b); min_bus = min(c,d);

    cout << min_train + min_bus << endl;

    return 0;
}

