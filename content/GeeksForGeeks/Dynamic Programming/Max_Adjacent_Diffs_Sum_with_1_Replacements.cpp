class Solution {
	public:
	int maxDiffSum(vector<int>& arr) {
		int n = arr.size();
		//time => O(n)
    //space => O(n*2)
    
		// base case
		if (n == 1)
			return 0;
		
		if (n == 2) {
			int first_case = abs(arr[0] - arr[1]);
			int a = max(arr[0], arr[1]);
			
			return max(first_case, abs(a - 1));
		}
		
		vector<vector<int>> dp(n, vector<int>(2, 0));
		
		dp[0][0] = arr[0];
		dp[0][1] = arr[1];
		
		dp[1][0] = max(abs(arr[1] - arr[0]), abs(arr[1] - 1));
		dp[1][1] = max(abs(1 - arr[0]), abs(1 - 1));
		
		for (int i = 2; i<n; i++) {
			dp[i][0] = max(
			abs(arr[i] - arr[i - 1]) + dp[i - 1][0],
			abs(arr[i] - 1) + dp[i - 1][1]
			);
			
			dp[i][1] = max(
			abs(1 - arr[i - 1]) + dp[i - 1][0],
			abs(1 - 1) + dp[i - 1][1]
			);
		}
		 
		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};
