#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;


int mulp(long long temp1, long long temp2) {
    long long ans = 0;
    ans = (temp1 % mod * temp2 % mod) % mod;
    return (int)ans;
}


int balancedBTs(int h, int dp[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
   if(h < 0)
       return 0;
   if(h == 1 || h == 0){
       return 1;
   }
   if(dp[h] != 0){
       return dp[h];
   }
    
   int ans1, ans2; 
   long long temp1 = (balancedBTs(h - 2, dp) % mod); 
   long long temp2 = (balancedBTs(h - 1, dp) % mod);
   ans1 = mulp(temp1, temp2) ;
   ans2 = mulp(temp2, temp2) ;
    
   return dp[h] = (2 * ans1 % mod + ans2 % mod) % mod;
}




int binaryTreesOfHeightH(int h) {
    // Write your code here
  int dp[10000001] = {0};
  return balancedBTs(h, dp);
}

