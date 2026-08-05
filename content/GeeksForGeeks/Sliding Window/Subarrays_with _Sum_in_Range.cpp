#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& arr,int value){
        
        long long sum = 0;
        long long ans = 0;
        
        int n = arr.size();
        
        int i=0;
        
        for(int j=0;j<n;j++){
            sum += arr[j];
            
            while(sum > value){
                sum -= arr[i++];
            }
            
            ans += (j-i+1);
        }
        
        return ans;
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        long long part1 = solve(arr,r);
        long long part2 = solve(arr,l-1);
        
        int ans = (int)(part1 - part2);
        
        
        //time complexity => o(n)
        //space complexity => o(1)
        
        return ans;
        
    }
};