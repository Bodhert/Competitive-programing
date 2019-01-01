typedef pair<int, int> ii;

void SlidingWindow(int A[], int n, int K)
{
    deque<ii> window;
    for (int i = 0; i < n; i++)
    {
      while (!window.empty() && window.back().first >= A[i])
       window.pop_back();
    
      window.push_back(ii(A[i], i));

      while(window.front().second <= i - K)
        window.pop_front()

        if(i + 1 >= K)
            printf("%d\n", window.front().first);
    }
}