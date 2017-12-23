/*
ID: alejand24
TASK: barn1
LANG: C++11
*/

#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int maxNumberDoors, stalls, totalCows, cow, ans1;
    vi data; vector<iii> gaps;
    fin >> maxNumberDoors >> stalls >> totalCows;
    ans1 = totalCows;

    for(int i = 0; i < totalCows ; ++i)
    {
        fin >> cow;
        data.push_back(cow);
    }

    sort(data.begin(), data.begin() + data.size());

    for(int i = 0; i < data.size()-1; ++i)
    {
        int gap1 = (data[i+1] - data[i]) - 1;
        if(gap1  != 0) gaps.push_back(iii(gap1,ii(data[i],data[i+1])));
    }

    sort(gaps.begin(), gaps.begin() + gaps.size());


    int boards = gaps.size() + 1;

    while(boards > maxNumberDoors)
    {
        if(!gaps.empty())
        {
         int temp = gaps[0].second.second - gaps[0].second.first - 1;
         ans1 += temp;
         boards--;
         gaps.erase(gaps.begin());
        }
    }
    fout << ans1 << endl;

    return 0;
}

