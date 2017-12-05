/*
ID: alejand24
TASK: transform
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;

const int MAXN = 11;
char Bsquare[MAXN][MAXN] , Asquare[MAXN][MAXN], temp[MAXN][MAXN];
int N;

void printMatrix()
{
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

void reflect()
{
    char localTemp[MAXN][MAXN];
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
            localTemp[i][j] = temp[i][j];
        }
    }


    for(int i = 0;  i < N; ++i)
    {
     int col = N-1;
     for(int j = 0 ; j < N; ++j)
     {
        temp[i][col] = localTemp[i][j];
        col--;
     }

    }
}

void rotate90()
{
    char localTemp[MAXN][MAXN];
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
            localTemp[i][j] = temp[i][j];
        }
    }

    int col = N-1;
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
            temp[j][col] = localTemp[i][j];
        }
     col--;
    }
}

void rotate270()
{
    rotate90();
    rotate90();
    rotate90();
}

void rotate180()
{
    rotate90();
    rotate90();
}

void clean()
{
    for(int i = 0;  i < MAXN; ++i)
    {
        for(int j = 0 ; j < MAXN; ++j)
        {
            Bsquare[i][j] = Asquare[i][j] = temp[i][j] = '.';
        }
    }
}

void restore()
{
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
            temp[i][j] = Bsquare[i][j];
        }
    }
}

bool equals()
{
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
          if(temp[i][j] != Asquare[i][j]) return false;
        }
    }
    return true;
}

int main()
{

    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    clean();

    vector<int> ans;
    char in;
    cin >> N;
    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
           cin >> in;
           Bsquare[i][j] = in;
           temp[i][j] = in;
        }
    }

    for(int i = 0;  i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
           cin >> in;
           Asquare[i][j] = in;
        }
    }

    rotate90();
    if(equals()) ans.push_back(1);
    restore();

    rotate180();
    if(equals()) ans.push_back(2);
    restore();

    rotate270();
    if(equals()) ans.push_back(3);
    restore();

    reflect();
    if(equals()) ans.push_back(4);
    restore();

    reflect();
    rotate90();
    if(equals()) ans.push_back(5);
    restore();

    reflect();
    rotate180();
    if(equals()) ans.push_back(5);
    restore();

    reflect();
    rotate270();
    if(equals()) ans.push_back(5);
    restore();

    if(equals()) ans.push_back(6);

    ans.push_back(7);

    //printMatrix();

    cout << ans[0] << endl;
    return 0;
}

