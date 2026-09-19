class Solution {
	public:
	
	int lcs(int i, int j, string& s1, string& s2, vector<vector<int>> & dp) {
		// base case
		int n = s1.size();
		int m = s2.size();
		
		if (i >= n || j >= m)
			return 0;
		
		if (dp[i][j] != -1)
			return dp[i][j];
		
		if (s1[i] == s2[j]) {
			return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, dp);
		}
		else {
			return dp[i][j] = max(lcs(i + 1, j, s1, s2, dp), lcs(i, j + 1, s1, s2, dp));
		}
	}
	
	int bottomUp(string& s1, string& s2, int c1, int c2) {
		if (s1.length() < s2.length()) {
			swap(s1, s2);
			swap(c1, c2);
		}
		
		int n = s1.size();
		int m = s2.size();
		
		vector<int> pre(m + 1, 0);
		vector<int> curr(m + 1, 0); // min(n,m)
		
		// tc	//(n*m)
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				
				if (s1[i - 1] == s2[j - 1]) {
					curr[j] = 1 + pre[j - 1];
				}
				else {
					curr[j] = max(pre[j], curr[j - 1]);
				}
				
			}
			
			swap(pre, curr);
		}
		
		int length = pre[m];
		
		return (n - length) *1LL*c1 + (m - length) * 1LL * c2;
	}
	
	int findMinCost(string &s1, string &s2, int costS1, int costS2) {
		int n = s1.size();
		int m = s2.size();
		
		return bottomUp(s1, s2, costS1, costS2);
	}
};
