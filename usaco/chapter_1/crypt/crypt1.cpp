/*
ID: alejand24
TASK: crypt1
LANG: C++11
*/

#include <bits/stdc++.h>
#define D(x) cout << "DEBUG: " << #x "=" << x << endl;
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
bitset<10> numbers;

template <class T> string toStr(const T &x)
{stringstream s; s << x; return s.str();}

template <class T> int toInt (const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


bool existsFactors(int num)
{
    string currNum = toStr<int>(num);
    for(int i = 0; i < currNum.size(); ++i)
    {
        char curDigit = currNum[i];
        int curDigitPos = toInt<char>(curDigit);
        //D(numbers[curDigitPos]);
        if(!numbers[curDigitPos]) return false;
    }
    return true;
}

bool existsPartialProduct(int num)
{
   string currNum = toStr<int>(num);
   if(currNum.size() != 3) return false;

   for(int i = 0; i < currNum.size(); ++i)
    {
        char curDigit = currNum[i];
        int curDigitPos = toInt<char>(curDigit);
        if(!numbers[curDigitPos]) return false;
    }
   return true;
}

bool existsProduct(int num)
{
   string currNum = toStr<int>(num);
   if(currNum.size() != 4) return false;

   for(int i = 0; i < currNum.size(); ++i)
    {
        char curDigit = currNum[i];
        int curDigitPos = toInt<char>(curDigit);
        if(!numbers[curDigitPos]) return false;
    }
   return true;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);

    int N, num , cont = 0;
    cin >> N;
    for(int i = 0; i < N; ++i)  {cin >> num; numbers[num] = 1;}

    for(int i = 100; i <= 999; ++i )
    {
        if(existsFactors(i))
        {
            for(int j = 10; j <= 99; ++j)
            {
                if(existsFactors(j))
                {
                    int first = j % 10;
                    int second = j / 10;
                    int firstP = first * i;
                    int secondP =  second * i;
                    if(existsPartialProduct(firstP) && existsPartialProduct(secondP))
                    {
                        int product = i*j;
                        if(existsProduct(product)) cont++;
                    }
                }
            }
        }
    }

    cout << cont << endl;




    return 0;
}

