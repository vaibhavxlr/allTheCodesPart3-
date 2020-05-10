#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli T, COUNT = 1;
    cin >> T;
    lli dp[20000001] = {0};
    for(int i = 2; i <= 20000000; i++){
        lli op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(i % 2 == 0)
          op2 = dp[i/2];
        
        if(i % 3 == 0)
          op3 = dp[i/3];
          
        op1 = dp[i-1];
        dp[i] = min(min(op2, op3), op1) + 1;
        // cout << dp[i] << endl;
    }
    while(T--){
       lli N;
       cin >> N;
       cout << "Case " << COUNT << ": " << dp[N] << endl;
       COUNT++;
    }
  
    
}
    