#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    int **dp = new int *[21];
    
    for(int i = 0; i < m; i++)
      { dp[i] = new int[21];
      }
    
    dp[m - 1][n - 1] = input[m - 1][n - 1];
    
    for(int i = m - 2; i >= 0; i--){
        dp[i][n-1] = input[i][n - 1] + dp[i + 1][n - 1];
    }
    
    
    for(int i = n - 2; i >= 0; i--){
        dp[m - 1][i] = input[m - 1][i] + dp[m - 1][i + 1];
    }
    
    for(int i = m - 2; i >= 0; i--){
      for(int j = n - 2; j >= 0; j--){
        dp[i][j] = input[i][j] + min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
      }
    }
    return dp[0][0];
    
    
}