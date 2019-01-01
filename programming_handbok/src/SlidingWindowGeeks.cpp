
/*para una explicacion mas detallada revisar Sliding Window 
Maximum de geek for geeks*/
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    std::deque<int> Qi(k);

    int i;
    for (i = 0; i < k; ++i)
    {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back(); // Remove from rear

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    for (; i < n; ++i)
    {
        cout << arr[Qi.front()] << " ";

        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front(); // Remove from front of queue

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }

    cout << arr[Qi.front()];
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
