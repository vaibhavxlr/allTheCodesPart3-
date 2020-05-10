#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

long staircase(int n, long dp[]){
    
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(n == 3)
        return 4;
    
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    long ans1, ans2, ans3;
    ans1 = ans2 = ans3 = 0;
    ans1 = staircase(n - 1, dp);
//    if(n >= 2)
    ans2 = staircase(n - 2, dp);
   // if(n >= 3)
    ans3 = staircase(n - 3, dp);
    //cout << ans1 << endl << ans2 << endl << ans3 << endl;
    long iinal = (ans1 + ans2 + ans3) ;
    //cout << dp[n] << endl;
    return dp[n] = iinal;
    
    
}




long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long dp[71];
    dp[0] = {0};
    for(int i = 1; i < 71; i++) dp[i] = -1;
    
     return staircase(n, dp);
   // cout << ans;
    
}

main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    cout << staircase(T);
  
    
}
    