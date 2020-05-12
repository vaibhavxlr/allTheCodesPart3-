#include <bits/stdc++.h>

int minCount(int n , int dp[]) {
    if(n <= 0){
        return 0;
    }
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++){
        int ans = INT_MAX;
        for(int j = 1; j * j <= i; j++){
            int subpro = (1 + dp[i - (j* j)]);
            ans = min(ans, subpro);
        }
        dp[i] = ans;
    }
    return dp[n];
}




int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int dp[1001] = {0};
    for(int i = 1; i < 1001; i++){
        
        dp[i] = -1;
    }
    return minCount(n, dp);
    
}