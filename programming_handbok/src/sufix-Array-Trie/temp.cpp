
int owner(int idx) { return (idx < n - m - 1) ? 1 : 2; }

ii stringMatching()
{                      // string matching in O(m log n)
    int lo = 0, hi = n - 1, mid = lo; // valid matching 
                                     //= [0..n-1]
    while (lo < hi)
    { // find lower bound
        mid = (lo + hi) / 2; // this is round down
        int res = strncmp(T + SA[mid], P, m); 
        // try to find P in suffix 'mid'
        if (res >= 0)
            hi = mid; 
            // prune upper half (notice the >= sign)
        else
            lo = mid + 1; 
            // prune lower half including mid
    }       // observe `=' in "res >= 0" above
    if (strncmp(T + SA[lo], P, m) != 0)
        return ii(-1, -1); // if not found
    ii ans;
    ans.first = lo;
    lo = 0;
    hi = n - 1;
    mid = lo;
    while (lo < hi)
    { // if lower bound is found, find upper bound
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if (res > 0)
            hi = mid; // prune upper half
        else
            lo = mid + 1; 
            // prune lower half including mid
    }       // (notice the selected branch when res == 0)
    if (strncmp(T + SA[hi], P, m) != 0)
        hi--; // special case
    ans.second = hi;
    return ans;
} // return lower/upperbound as first/second item of 
  // the pair, respectively

ii LRS()
{ // returns a pair (the LRS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++) // O(n), start from i = 1
        if (LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}


ii LCS()
{ // returns a pair (the LCS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++) // O(n), start from i = 1
        if (owner(SA[i]) != owner(SA[i - 1]) && 
                                        LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}