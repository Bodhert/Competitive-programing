
// returns what string is the owner of
// the suffix, if there  are more than two
// string this line has to be modified to the num of
// strings in the input
int owner(int idx) { return (idx < n - m - 1) ? 1 : 2; }

ii LCS()
{ // returns a pair (the LCS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++) // O(n), start from i = 1
        if (owner(SA[i]) != owner(SA[i - 1]) && 
                                        LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

int main()
{
    // LCS demo
    //printf("\nRemember, T = '%s'\nNow,
    //enter another string P:\n", T);
    // T already has '$' at the back
    strcpy(P, "CATA");
    m = (int)strlen(P);
    // if '\n' is read, uncomment the next line
    //P[m-1] = 0; m--;
    strcat(T, P);       // append P
    strcat(T, "#");     // add '$' at the back
    n = (int)strlen(T); // update n

    // reconstruct SA of the combined strings
    constructSA(); // O(n log n)

    ans = LCS();
    // find the longest common substring between T and P
    char lcsans[MAX_N];
    strncpy(lcsans, T + SA[ans.second], ans.first);
    printf("\nThe LCS is '%s' with length = %d\n",
           lcsans, ans.first);
}
