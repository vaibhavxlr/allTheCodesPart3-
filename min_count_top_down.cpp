#include <bits/stdc++.h>

int minCount(int n , int dp[]) {
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 3;
    }
    
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    ///vector<int> v;
    int ans = INT_MAX;
    
    for(int i = 1; (i * i) <= n; i++){
        int subprob = minCount((n - (i * i)), dp);
        ans = min(ans, subprob + 1);
    }
    
    dp[n] = ans;
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