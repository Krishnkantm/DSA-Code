#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
       int n = arr.size();
       
       //Time Complexity = O(n) + O(nlongn) => o(nlongn)
       //space complexity = o(n)
       
       sort(arr.begin(),arr.end());
       
       int ans = 0;
       
       int i=0;
       int j = i+1;
       
       
       while(j<n){
           
           while(j<n && abs(arr[j]- arr[i]) < k){
               int remaining = j-i-1;
               ans += 1 + remaining;
               j++;
           }
           
           i++;
       }
       
       return ans;
    }
};