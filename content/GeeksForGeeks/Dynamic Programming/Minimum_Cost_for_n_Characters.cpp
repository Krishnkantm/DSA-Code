class Solution {
	public:
	int solve(int n, int i, int d, int c, vector<int>& dp) {
		// base case
		if (n == 0)
			return 0;
		
		if (n == 1)
			return i;
		
		if (dp[n] != -1) {
			return dp[n];
		}
		
		int result = i + solve(n - 1, i, d, c, dp);
		
		// copy
		if (n % 2 == 0) {
			result = min(result, c + solve(n/2, i, d, c, dp));
		}
		else {
			result = min(result, solve((n + 1)/2, i, d, c, dp) + c + d);
		}
		
		return dp[n] = result;
	}
	
	int minCost(int n, int i, int d, int c) {
		vector<int> dp(n + 1, -1) // O(n) + O(n)
		
		return solve(n, i, d, c, dp);
	}
};
