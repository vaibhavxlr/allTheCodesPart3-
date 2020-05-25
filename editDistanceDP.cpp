#include <iostream>
#include <vector>
using namespace std;

// int editDistance(string s1, string s2, int **dp){
    
//     if(s1.size() == 0 || s2.size() == 0){
//         return dp[s1.size()][s2.size()] = max(s1.size(), s2.size());
//     }
//     if(dp[s1.size()][s2.size()] != -1)
//         return dp[s1.size()][s2.size()];
    
//     //int ans = 0;
//     if(s1[0] == s2[0]){
//         //ans++;
//         dp[s1.size()][s2.size()] = editDistance(s1.substr(1), s2.substr(1), dp);
//     }
//     else{
//         int x = 1 + editDistance(s1.substr(1), s2, dp);
//         int y = 1 + editDistance(s1, s2.substr(1), dp);
//         int z = 1 + editDistance(s1.substr(1), s2.substr(1), dp);
//         dp[s1.size()][s2.size()] = min(x, min(y, z));
//     }    
    
//     return dp[s1.size()][s2.size()];
// }

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */

	//write your code here
   int **dp = new int*[15];
   for(int i = 0; i < 15; i++){
       dp[i] = new int[15];
    
   }
   
   dp[0][0] = 0;
   for(int i = 1; i <= s2.size(); i++){
       dp[0][i] = i;
   } 
   
   for(int i = 1; i <= s1.size(); i++){
       dp[i][0] = i;
   } 
   
   int m = s1.size();
   int n = s2.size();
   
   for(int i = 1; i <= s1.size(); i++){
      for(int j = 1; j <= s2.size(); j++){
          if(s1[m-i] == s2[n - j]) 
             dp[i][j] = dp[i - 1][j - 1];
          else
             dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
          
       }
   }
    
   return dp[s1.size()][s2.size()];
}