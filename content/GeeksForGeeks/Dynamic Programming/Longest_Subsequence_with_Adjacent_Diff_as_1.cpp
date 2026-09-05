class Solution {
	public:
	int longestSubseq(vector<int>& arr) {
		int n = arr.size();
		
		if (n == 1)
			return 1;
		
		unordered_map<int, int> dp; // O(n)
		
		// time = o(n)
    //space = O(n)
		for (int i = 0; i<n; i++) {
			
			if (dp.count(arr[i]-1) || dp.count(arr[i]+1)) {
				dp[arr[i]] = 1 + max(dp[arr[i]-1], dp[arr[i]+1]);
			}
			else {
				dp[arr[i]] = 1;
			}
		}
		
		int ans = 0;
		
		for (auto &it : dp) {
			ans = max(ans, it.second);
		}
		
		return ans;
	}
};
