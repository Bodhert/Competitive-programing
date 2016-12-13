// Maximum Sum

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, A[101][101], maxSubRect, subRect;

void printMath(int n){  // ad this method for debug purposes
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

void printPos(int i, int j){  // ad this method for debug purposes
  cout << A[i][j] << " " << endl;
}


int main() {     // O(n^3) 1D DP + greedy (Kadane's) solution, 0.008 s in UVa
  scanf("%d", &n);                    // the dimension of input square matrix
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
      if (j > 0) A[i][j] += A[i][j - 1];      // only add columns of this row i
    }

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int l = 0; l < n; l++)
    for (int r = l; r < n; r++) {
      subRect = 0;
      for (int row = 0; row < n; row++) {
	// Max 1D Range Sum on columns of this row i
	if (l > 0) subRect += A[row][r] - A[row][l - 1];
	else       subRect += A[row][r];
	
	// Kadane's algorithm on rows
	if (subRect < 0) subRect = 0;     // greedy, restart if running sum < 0
	maxSubRect = max(maxSubRect, subRect);
      }
    }
  
  printf("%d\n", maxSubRect);
  return 0;
}
