#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N;
    unsigned long int S;
    while(cin >> N >> S)
    {
      vector<int> vec;
      int num , ans1 , ans2;
      unsigned long int acum = 0;
      for(int i = 0; i < N; ++i)
      {
        cin >> num;
        vec.push_back(num);
      }

      bool found = false;
      for(int i = 0; i < vec.size() && !found; ++i)
      {
          acum = 0;
          for(int j = i; j < vec.size() && !found; ++j)
          {
              if(i == j) acum += vec[i];
              else acum += vec[j];

              if(acum == S)
              {
                  ans1 = i + 1; ans2 = j + 1;
                  found = true;
              }
              else if(acum > S) break;
          }
      }

      cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
