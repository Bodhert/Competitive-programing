#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
  ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll dx = abs(a - c), dy = abs(b - d);
    ll x, y;
    cin >> x >> y;

    if (dx % x || dy % y) {
        cout << "NO\n";
        return 0;
    }

    dx /= x, dy /= y;
    cout << (dy % 2 == dx % 2 ? "YES\n" : "NO\n");

}