#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100010          // second approach: O(n log n)
char T[MAX_N];                // the input string, up to 100K characters
int n;                        // the length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N];                 // for counting/radix sort

char P[MAX_N]; // the pattern string (for string matching)
int m;         // the length of pattern string

int Phi[MAX_N]; // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N]; // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                // and current suffix T+SA[i]
vector<ii> ans;
vector<string> words;
map<string, string> cleanAns;
char lcsans[MAX_N]; // for storing the answer
int maxLCP;         // gobal variable for storing the maximun size

void countingSort(int k)
{                                   // O(n)
    int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);         // clear frequency table
    for (i = 0; i < n; i++)         // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++) // shuffle the suffix array if necessary
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++) // update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA()
{ // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++)
        RA[i] = T[i]; // initial rankings
    for (i = 0; i < n; i++)
        SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1)
    {                           // repeat sorting process log n times
        countingSort(k);        // actually radix sort: sort based on the second item
        countingSort(0);        // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;  // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++) // compare adjacent suffixes
            tempRA[SA[i]] =     // if same pair => same rank r; otherwise, increase r
                (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n; i++) // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1)
            break; // nice optimization trick
    }
}

void computeLCP()
{
    int i, L;
    Phi[SA[0]] = -1;            // default value
    for (i = 1; i < n; i++)     // compute Phi in O(n)
        Phi[SA[i]] = SA[i - 1]; // remember which suffix is behind this suffix
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
        LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
}

int owner(int idx) { return (idx < n - m - 1) ? 1 : 2; }

void LCS()
{ // returns a pair (the LCS length and its index)
    int i, idx = 0;
    maxLCP = -1;
    for (i = 1; i < n; i++) // O(n), start from i = 1
        if (owner(SA[i]) != owner(SA[i - 1]) && LCP[i] >= maxLCP)
        {
            maxLCP = LCP[i], idx = i;
            ans.push_back(ii(maxLCP, idx));
        }
}

void clean()
{
    ans.clear();
    words.clear();
    cleanAns.clear();
    memset(T, 0, MAX_N);
    memset(P, 0, MAX_N);
    for (int i = 0; i < MAX_N; ++i)
    {
        RA[i] = 0;
        tempRA[i] = 0;
        SA[i] = 0;
        tempSA[i] = 0;
        c[i] = 0;
        Phi[i] = 0;
        PLCP[i] = 0;
        LCP[i] = 0;
    }
}

//cant forget to clean everything
// i have a bug with the char array
int main()
{
    // freopen("inUdebug", "r", stdin);

    scanf("%s", T);
    scanf("%s", P);
    n = (int)strlen(T);
    T[n++] = '$';
    m = (int)strlen(P);
    strcat(T, P);       // append P
    strcat(T, "#");     // add '$' at the back
    n = (int)strlen(T); // update n
    constructSA(); // O(n log n)
    computeLCP(); // O(n)
    LCS(); // find the longest common substring between T and P

    sort(ans.begin(), ans.end(), greater<ii>());
    for (int i = 0; i < ans.size(); ++i)
    {
        ii temp = ans[i];
        if (temp.first == maxLCP)
        {
            // cout << temp.first << " : " << temp.second << endl;
            memset(lcsans, 0, MAX_N);
            strncpy(lcsans, T + SA[temp.second], temp.first);
            // printf("\nThe LCS is '%s' with length = %d\n", lcsans, temp.first);
            string tempAns(lcsans);
            if (tempAns == "")
            {
                printf("No common sequence.\n");
                break;
            }
            // words.push_back(tempAns);
            if (!cleanAns.count(tempAns))
                cleanAns[tempAns] = tempAns;
        }
        else
            break;
    }

    if (!cleanAns.empty())
    {
        for (std::map<string, string>::iterator it = cleanAns.begin(); it != cleanAns.end(); ++it)
        {
            printf("%s\n", it->first.c_str());
        }
    }

    clean();

    while (scanf("%s", T) != EOF)
    {
        scanf("%s", P);
        printf("\n");
        // printf("T %s\n", T);
        // printf("P %s\n",P);
        // // strcpy(T, "atgc");
        n = (int)strlen(T);
        T[n++] = '$';
        // strcpy(P, "gctg");
        m = (int)strlen(P);
        // if '\n' is read, uncomment the next line
        // P[m-1] = 0; m--;
        strcat(T, P);       // append P
        strcat(T, "#");     // add '$' at the back
        n = (int)strlen(T); // update n
        // printf("concatenated %s\n", T);

        // reconstruct SA of the combined strings
        constructSA(); // O(n log n)
        // printf("\nThe Suffix Array of string T = '%s' is shown below (O(n log n) version):\n", T);
        // printf("i\tSA[i]\tSuffix\n");
        // for (int i = 0; i < n; i++)
        //     printf("%2d\t%2d\t%s\n", i, SA[i], T + SA[i]);
        computeLCP(); // O(n)
        // printf("\nThe LCP information of 'T+P' = '%s':\n", T);
        // printf("i\tSA[i]\tLCP[i]\tOwner\tSuffix\n");
        // for (int i = 0; i < n; i++)
        //     printf("%2d\t%2d\t%2d\t%2d\t%s\n", i, SA[i], LCP[i], owner(SA[i]), T + SA[i]);

        LCS(); // find the longest common substring between T and P

        sort(ans.begin(), ans.end(), greater<ii>());
        for (int i = 0; i < ans.size(); ++i)
        {
            ii temp = ans[i];
            if (temp.first == maxLCP)
            {
                // cout << temp.first << " : " << temp.second << endl;
                memset(lcsans, 0, MAX_N);
                strncpy(lcsans, T + SA[temp.second], temp.first);
                // printf("\nThe LCS is '%s' with length = %d\n", lcsans, temp.first);
                string tempAns(lcsans);
                if (tempAns == "")
                {
                    printf("No common sequence.\n");
                    break;
                }
                // words.push_back(tempAns);
                if (!cleanAns.count(tempAns))
                    cleanAns[tempAns] = tempAns;
            }
            else
                break;
        }

        if (!cleanAns.empty())
        {
            for (std::map<string, string>::iterator it = cleanAns.begin(); it != cleanAns.end(); ++it)
            {
                printf("%s\n", it->first.c_str());
            }
        }

        clean();
    }
    return 0;
}
