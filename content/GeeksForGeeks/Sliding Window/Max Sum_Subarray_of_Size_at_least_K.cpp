#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        //Time Complexity: O(n)
       //space Complexity: O(1)
        
        long long maxSum = arr[0];
        long long currSum = 0;
        
        long long result = LLONG_MIN;
        long long sum = 0;
        int j = 0;
        
        
        for(int i=0;i<n;i++){
            sum = sum +  1LL*arr[i];
            
            if(i >= k) sum = sum - 1LL *arr[i-k];
            
            if(i < k-1) continue;
            
            result = max(result,sum);
            
            if(i-k >= 0){
                currSum = max(arr[j]*1LL,currSum + arr[j]);
                maxSum = currSum;
                
                result = max(result,maxSum + sum);
                j++;
            }
            
        }
        
        return (int)result;
    }
};