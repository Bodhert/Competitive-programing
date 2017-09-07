#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int ans = 0;

// void posiblesSums(int start, int sum)
// {
//     if(nums.size() == start) return;
//     int val = sum +  nums[start];
//     if(val%10 != 0 && val > ans) ans = val;
//     //cout << "Valor: " << val << endl;
//     posiblesSums(start+1,val);
//     posiblesSums(start+1,sum);
// }


void subsetSums( int n)
{
    // There are totoal 2^n subsets
    long long total = 1<<n;
 
    // Consider all numbers from 0 to 2^n - 1
    for (long long i=0; i<total; i++)
    {
        long long sum = 0;
 
        // Consider binary reprsentation of
        // current i to decide which elements
        // to pick.
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                sum += nums[j];
 
        // Print sum of picked elements.
        //cout << sum << " ";
        if(sum % 10 != 0 && sum > ans) ans = sum;
    }
}

int main()
{ 
    int numbers, num;
    cin >> numbers;
    while(numbers--)
    {
        cin >> num;
        nums.push_back(num);
    }

    //posiblesSums(0,0);
    subsetSums(nums.size());

    cout << ans << endl;

    return 0;
}