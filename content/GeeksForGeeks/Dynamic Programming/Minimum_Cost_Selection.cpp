class Solution {
	public:
	int solve(int row, vector<vector<int>> & mat, int preCol, vector<vector<int>> & dp) {
		// base case
		if (row >= mat.size()) {
			return 0;
		}
		
		if (dp[row][preCol + 1] != -1) {
			return dp[row][preCol + 1];
		}
		
		int first = INT_MAX;
		
		if (preCol != 0) {
			first = mat[row][0] + solve(row + 1, mat, 0, dp);
		}
		
		int second = INT_MAX;
		if (preCol != 1) {
			second = mat[row][1] + solve(row + 1, mat, 1, dp);
		}
		
		int third = INT_MAX;
		if (preCol != 2) {
			third = mat[row][2] + solve(row + 1, mat, 2, dp);
		}
		
		return dp[row][preCol + 1] = min({first, second, third});
	}
	
	// iterative way
	int bottomUp(vector<vector<int>> & mat) {
		int n = mat.size();
		
		int pre0 = mat[0][0];
		int pre1 = mat[0][1];
		int pre2 = mat[0][2];
		
		// O(n)
		// space=> O(1)
		for (int i = 1; i<n; i++) {
			
			int curr0 = mat[i][0] + min(pre1, pre2);
			
			int curr1 = mat[i][1] + min(pre0, pre2);
			int curr2 = mat[i][2] + min(pre1, pre0);
			
			pre0 = curr0;
			pre1 = curr1;
			pre2 = curr2;
		}
		
		return min({pre0, pre1, pre2});
	}
	
	int minCost(vector<vector<int>> & mat) {
		int n = mat.size();
		
		return bottomUp(mat);
	}
};
