#include <bits/stdc++.h>

using namespace std;

int main()
{
    int actual = 2, next = 3;
    unsigned long long sum = 2;

    while(next <= 4000000)
    {

        int temp = next;
        next += actual;
        actual = temp;
        if(next <= 4000000 && next%2==0) sum+=next;
        cout << sum << endl;
    }

    return 0;
}

