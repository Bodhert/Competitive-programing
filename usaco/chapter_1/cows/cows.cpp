/*
ID: alejand24
TASK: milk2
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 5005;
ii intervals[MAXN];

int main()
{

    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    vii intervals;
    int N;
    int max_milked = 0;
    int max_noMilked = 0;
    int startC, endC;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> startC >> endC;
        intervals.push_back(ii(startC,endC));
    }

    sort(intervals.begin(),intervals.begin()+N);

    int start = intervals[0].first; int end_ = intervals[0].second;
    for(int i = 0; i < N; ++i)
    {
        int currentFirst = intervals[i].first; int currentSecond = intervals[i].second;
        if(currentFirst <= end_ )
        {
            if(currentSecond > end_) end_ = currentSecond;
            max_milked = max(max_milked, end_ - start);
        }
        else
        {
          start = currentFirst;
          max_noMilked = max(max_noMilked, currentFirst - end_);
          end_ = currentSecond;
          //D(currentFirst); D(end_);
        }
    }
    cout << max_milked << " " << max_noMilked << endl;

    return 0;
}

