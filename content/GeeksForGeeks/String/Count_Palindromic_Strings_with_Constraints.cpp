class Solution {
	public:
	int mod = 1e9 + 7;
	int palindromicStrings(int n, int k) {
		//space = > O(k)
    //time => O(n) + O(k)
    
		if (n == 1)
			return k % mod;
		
		if (n == 2)
			return 2*k % mod;
		
		vector<int> dp(k + 1, 0);
		
		dp[0] = 1;
		
		// O(k)
		for (int i = 1; i <= k - 2; i++) {
			dp[i] = (dp[i - 1] *1LL* (k - 1-i)) % mod;
		}
		
		int ans = (2*k + (k*(k - 1))) % mod;
		
		// O(n)
		for (int length = 4; length <= n; length++) {
			
			int first_half = length / 2;
			
			int first_two = (k*(k - 1)) % mod;
			int ways = dp[first_half - 2];
			
			if (length %2 != 0) {
				int remain = k - first_half;
				ans = (ans + ways* 1LL * remain*1LL * first_two) % mod;
			}
			else {
				ans = (ans + ways *1LL* first_two) % mod;
			}
		}
		
		return ans % mod;
	}
};
