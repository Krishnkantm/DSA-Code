class Solution {
  public:
    vector<int> findPairs(vector<int> &arr) {
      int n = arr.size();

      unordered_map<int, pair<int, int>> mp;

      // time ->O(n^2) ->
      // space -> O(n^2)
      
      vector<int> ans;

      // step1 we generate all pairs
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          int sum = arr[i] + arr[j];

          if (mp.count(sum)) {
            pair<int, int> p = mp[sum];

            int a = p.first, b = p.second;
            int c = i, d = j;

            if ((a != c && a != d) && (b != c && b != d)) {
               vector<int> curr = {a,b,c,d};
               
               if(ans.empty() || ans > curr){
                   ans = curr;
               }
            }
          }
          else{
              mp[sum] = {i,j};
          }
        }
      }
       
       
       if(ans.empty()){
        return {-1,-1,-1,-1};   
       }
       
       return ans;
    }
};
