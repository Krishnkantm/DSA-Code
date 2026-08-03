#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index , int n,vector<int>& stoneValue,vector<int>& dp){
        //base case
        if(index >= n){
            return 0;
        }

        if(dp[index] != INT_MIN){
            return dp[index];
        }

        int first = INT_MIN;
        if(index < n){
            first = stoneValue[index] - solve(index+1,n,stoneValue,dp);
        }

        int second = INT_MIN;
        if(index+1 < n){
            second = (stoneValue[index] + stoneValue[index+1]) - solve(index+2,n,stoneValue,dp);
        }

        int third = INT_MIN;
        if(index+2 < n){
            third = (stoneValue[index]+ stoneValue[index+1] + stoneValue[index+2]) - solve(index+3,n,stoneValue,dp);
        }

        return dp[index] = max(first,max(second,third));
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n+1,INT_MIN);
        int ans  = solve(0,n,stoneValue,dp);

        if(ans > 0){
            return "Alice";
        }
        else if(ans == 0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};