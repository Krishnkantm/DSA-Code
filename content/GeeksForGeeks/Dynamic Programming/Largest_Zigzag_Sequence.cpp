class Solution {
	public:
	int solve(int row, vector<vector<int>> & mat, int preCol, vector<vector<int>> & dp) {
		// base case
		if (row >= mat.size())
			return 0;
		
		if (dp[row][preCol + 1] != -1) {
			return dp[row][preCol + 1];
		}
		
		int result = 0;
		
		for (int j = 0; j<mat[0].size(); j++) {
			if (preCol != j) {
				result = max(result, mat[row][j] + solve(row + 1, mat, j, dp));
			}
		}
		
		return dp[row][preCol + 1] = result;
	}
	
	int bottomUp(vector<vector<int>> & mat) {
		int n = mat.size();
		
		vector<vector<int>> dp(n, vector<int>(n, 0)); // O(n*n)
		
		for (int j = 0; j<n; j++) {
			dp[0][j] = mat[0][j];
		}
		
		// (n*n*(n))
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<n; j++) {
				
				for (int pre = 0; pre<n; pre++) {
					if (pre == j)
						continue;
					
					dp[i][j] = max(dp[i][j], dp[i - 1][pre]+mat[i][j]);
				}
			}
		}
		
		int result = 0;
		
		// O(n)
		for (int j = 0; j<n; j++) {
			result = max(result, dp[n - 1][j]);
		}
		
		return result;
	}
	
	int spaceOptimization(vector<vector<int>> & mat) {
		int n = mat.size();
		
		vector<int> pre(n, 0);
		vector<int> curr(n, 0);
		
		for (int j = 0; j<n; j++) {
			pre[j] = mat[0][j];
		}
		
		// (n*n*(n))
		for (int i = 1; i<n; i++) {
			
			fill(curr.begin(), curr.end(), 0);
			
			for (int j = 0; j<n; j++) {
				for (int p = 0; p<n; p++) {
					if (p == j)
						continue;
					
					curr[j] = max(curr[j], pre[p]+mat[i][j]);
				}
			}
			
			pre = curr;
		}
		
		int result = 0;
		
		// O(n)
		for (int j = 0; j<n; j++) {
			result = max(result, pre[j]);
		}
		
		return result;
	}
	
	int zigzagSequence(vector<vector<int>> & mat) {
		
		return spaceOptimization(mat);
	}
};
