/*
ID: alejand24
TASK: friday
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;


using namespace std;
int initialYear = 1900;
int DayOfWeek = 1; // 0 -> sunday, // 1 -> monday ... 6 -> saturday
int Day = 1;
int days[7] = {0,0,0,0,0,0,0};




int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int N;
    cin >> N;

    int period = initialYear + (N-1);

    for(int year = initialYear; year <= period; ++year)
    {
        bool leap = false;
        if(((year%100) == 0) && ((year%400) == 0)) leap = true;
        else if(((year%100) != 0) && ((year%4) == 0)) leap = true;

        for(int tempMonth = 0; tempMonth <= 11; ++tempMonth)
        {
            int posThirt = (DayOfWeek + 12) % 7;
            days[posThirt]++;
            DayOfWeek = posThirt;
            int totalDays;

            if(tempMonth == 3 || tempMonth == 5 || tempMonth == 8 || tempMonth == 10) totalDays = 30;
            else if(tempMonth == 1 && !leap)  totalDays = 28;
            else if(tempMonth == 1 && leap) totalDays = 29;
            else totalDays = 31;

            int lastDayofTheWeek = (DayOfWeek + (totalDays-13)) % 7;
            DayOfWeek = (lastDayofTheWeek + 1) %7;
            //month = (month + 1) % 12;
        }
    }

    cout << days[6] << " ";
    cout << days[0] << " ";
    cout << days[1] << " ";
    cout << days[2] << " ";
    cout << days[3] << " ";
    cout << days[4] << " ";
    cout << days[5] << endl;


    return 0;
}

