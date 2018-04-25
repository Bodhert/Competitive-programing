#include<bits/stdc++.h>
using namespace std;


int main()
{
    unsigned long long squares_ = 0;
    unsigned long long squares_individual = 0;

    squares_ =  (100*(100+1))/2;
    squares_ *= squares_;

    cout << squares_ << endl;


    for(int i = 1; i <= 100; ++i)
        squares_individual += i*i;

    cout << squares_individual << endl;
    cout <<  squares_ - squares_individual << endl;

    return 0;
}