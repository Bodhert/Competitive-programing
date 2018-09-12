int Phi[MAX_N]; // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N]; // LCP[i] stores the LCP between
// previous suffix T+SA[i-1]
// and current suffix T+SA[i]

char P[MAX_N]; // the pattern string (for string matching)
int m;         // the length of pattern string
int n;         // the length of input string

// returns what string is the owner of
// the suffix, if there  are more than two
// string this line has to be modified to the num of
// strings in the input
int owner(int idx) { return (idx < n - m - 1) ? 1 : 2; }

void computeLCP()
{
    int i, L;
    Phi[SA[0]] = -1;            // default value
    for (i = 1; i < n; i++)     // compute Phi in O(n)
        Phi[SA[i]] = SA[i - 1]; // remember which suffix
                                // is behind
                                // this suffix
    for (i = L = 0; i < n; i++)
    { // compute Permuted LCP in O(n)
        if (Phi[i] == -1)
        {
            PLCP[i] = 0;
            continue;
        } // special case
        while (T[i + L] == T[Phi[i] + L])
            L++; // L increased max n times
        PLCP[i] = L;
        L = max(L - 1, 0); // L decreased max n times
    }
    for (i = 0; i < n; i++)   // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the
                              // correct position
}

int main()
{
    computeLCP(); // O(n)
    printf("\nThe LCP information of 'T+P' = '%s':\n", T);
    printf("i\tSA[i]\tLCP[i]\tOwner\tSuffix\n");
    for (int i = 0; i < n; i++)
        printf("%2d\t%2d\t%2d\t%2d\t%s\n", i,
               SA[i], LCP[i], owner(SA[i]), T + SA[i]);
    return 0;
}