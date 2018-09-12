typedef pair<int, int> ii;

ii LRS()
{ // returns a pair (the LRS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++) // O(n), start from i = 1
        if (LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

int main()
{
    // LRS demo
    ii ans = LRS();
    // find the LRS of the first input string
    char lrsans[MAX_N];
    strncpy(lrsans, T + SA[ans.second], ans.first);
    printf("\nThe LRS is '%s' with length = %d\n\n",
           lrsans, ans.first);
}
