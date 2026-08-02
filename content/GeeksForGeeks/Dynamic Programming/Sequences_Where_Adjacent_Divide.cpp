#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    //o(n) * o(M) *o(M) => o(N*M^2)
    int solve(int n,int m,int prev,vector<vector<int>>& dp){
        //base case
        if(n == 0){
            return 1;
        }
        
        if(dp[n][prev+1] != -1){
            return dp[n][prev+1];
        }
        
        int result = 0;
        
        for(int i=1;i<=m;i++){
            
            if(prev == -1){
               result += solve(n-1,m,i,dp);
            }
            else if((prev % i == 0) || (i % prev == 0)){
               result += solve(n-1,m,i,dp);
            }
        }
        
        return dp[n][prev+1] =  result;
    }
    
    int count(int n, int m) {
       
       vector<vector<int>> dp(n+1,vector<int>(m+2,-1));
       // space => O(N*M)
      return  solve(n,m,-1,dp);
    }
};