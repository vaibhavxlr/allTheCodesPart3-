#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int minC(int **input, int m, int n, int row, int col, int **dp) {
    
    
    if((row == m - 1) && col == n - 1){
        return input[row][col];
    }
    
    if(dp[row][col] != -1){
        return dp[row][col];
    }

    int x, y, z;
    x = y = z = INT_MAX;
    if(row < m -1)
    	 x = minC(input, m, n, row + 1, col, dp);
    if(col < n - 1)
    	 y = minC(input, m, n, row, col + 1, dp);
    if(row < m -1 && col < n - 1)
    	 z = minC(input, m, n, row + 1, col + 1, dp);
    
    dp[row][col] = min(min(x, y), z) + input[row][col];
    return dp[row][col];
    
}



int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    int **dp = new int *[21];
    
    for(int i = 0; i < m; i++)
      { dp[i] = new int[21];
        for(int j = 0; j < n ; j++)
            dp[i][j] = -1;
      }
    
    return minC(input, m, n, 0, 0, dp);
    
    
}
