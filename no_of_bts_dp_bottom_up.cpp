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
   dp[0] = 1;
   dp[1] = 1;

   for(int i = 2; i <= h; i++) {
       int temp1 = 2 * mulp(dp[i - 1], dp[i - 2])% mod;
       int temp2 = mulp(dp[i - 1], dp[i - 1])  % mod;
       dp[i] = (temp1 % mod  + temp2 % mod) % mod;
       
   }
   return dp[h];
}




int binaryTreesOfHeightH(int h) {
    // Write your code here
  int dp[10000001] = {0};
  return balancedBTs(h, dp);
}

