#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int path [N];
int ways = 0;

void recursiveBruteForce(int pos)
{
    if (pos > N)
    {
        return;
    }
    if (pos == N)
    {
        ways++;
        return;
    }
    recursiveBruteForce(pos+1);
    recursiveBruteForce(pos+2);
}

int main()
{
    recursiveBruteForce(0);
    cout << ways << endl;
    return 0;
}