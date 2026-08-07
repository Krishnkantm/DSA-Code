#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFriendsPairings(int n) {
        vector<int> dp(n+1,0);
        
        //Time Complexity => o(n)
        //Space Complexity => o(n)
        for(int i=0;i<=n;i++){
            if(i <= 2){
                dp[i] = i;
            }
            else{
                dp[i] = dp[i-1] + dp[i-2] * (i-1);
            }
        }
        
        return dp[n];
    }
};
