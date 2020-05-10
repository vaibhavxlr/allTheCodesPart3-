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
    lli N, M;
    vector <lli>v;
    cin >> N >> M;
    while(M--){
        lli a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    lli dp[1000];
    for(lli i = 1; i < 1000; i++) dp[i] = -1;
    dp[0] = 0;
    
    
    for(lli j = 1; j <= N; j++){   
        lli minm = INT_MAX;
        for(lli i : v){
            if(i <= j)    
               minm = min(minm, dp[j - i]);
            else
               break;
        }
        dp[j] = minm + 1;
    }
    
    cout << dp[N];
}
    