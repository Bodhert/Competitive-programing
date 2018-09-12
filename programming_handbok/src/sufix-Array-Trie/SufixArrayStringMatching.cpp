typedef pair<int, int> ii;
char P[MAX_N]; // the pattern string (for string matching)
int m;         // the length of pattern string

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

int main()
{
    // stringMatching demo
    //printf("\nNow, enter a string P below, 
    //we will try to find P in T:\n");
    strcpy(P, "A");
    m = (int)strlen(P);
    // if '\n' is read, uncomment the next line
    //P[m-1] = 0; m--;
    ii pos = stringMatching();
    if (pos.first != -1 && pos.second != -1)
    {
        printf("%s is found SA[%d..%d] of %s\n", P,
                 pos.first, pos.second, T);
        printf("They are:\n");
        for (int i = pos.first; i <= pos.second; i++)
            printf("  %s\n", T + SA[i]);
    }
    else
        printf("%s is not found in %s\n", P, T);

    return 0;
}