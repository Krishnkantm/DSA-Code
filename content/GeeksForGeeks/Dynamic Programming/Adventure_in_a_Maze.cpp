class Solution {
	public:
	int mod = 1000000007;
	
	// numeber of valid path
	int solve1(int i, int j, vector<vector<int>> & grid, vector<vector<int>> & dp) {
		// base case
		if (i >= grid.size() - 1 && j >= grid[0].size() - 1) {
			
			return 1;
		}
		
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		
		int ans = 0;
		
		if (grid[i][j] == 1 && j + 1 < grid[0].size()) {
			ans += solve1(i, j + 1, grid, dp) % mod;
		}
		else if (grid[i][j] == 2 && i + 1 < grid.size()) {
			ans += solve1(i + 1, j, grid, dp) % mod;
		}
		else if (grid[i][j] == 3) {
			int first = 0;
			
			if (j + 1 < grid[0].size()) {
				first += solve1(i, j + 1, grid, dp) % mod;
			}
			
			int second = 0;
			
			if (i + 1 < grid.size()) {
				second += solve1(i + 1, j, grid, dp) % mod;
			}
			
			ans = (ans + (first + second) % mod) % mod;
		}
		
		return dp[i][j] = ans % mod;
	}
	
	int solve2(int i, int j, vector<vector<int>> & grid, vector<vector<int>> & dp) {
		// base case
		
		if (i >= grid.size() || j >= grid[0].size()) {
			
			return INT_MIN;
		}
		
		if (i == grid.size() - 1 && j == grid[0].size() - 1) {
			return grid[i][j];
		}
		
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		
		if (grid[i][j] == 1) {
			int next = solve2(i, j + 1, grid, dp);
			
			if (next == INT_MIN) {
				return dp[i][j] = next;
			}
			else {
				return dp[i][j] = next + grid[i][j];
			}
		}
		
		if (grid[i][j] == 2) {
			int next = solve2(i + 1, j, grid, dp);
			
			if (next == INT_MIN) {
				return dp[i][j] = next;
			}
			else {
				return dp[i][j] = next + grid[i][j];
			}
		}
		
		if (grid[i][j] == 3) {
			int first = INT_MIN;
			
			if (j + 1 < grid[0].size()) {
				first = solve2(i, j + 1, grid, dp);
			}
			
			int second = INT_MIN;
			
			if (i + 1 < grid.size()) {
				second = solve2(i + 1, j, grid, dp);
			}
			
			if (first == INT_MIN && second == INT_MIN) {
				return dp[i][j] = INT_MIN;
			}
			
			return dp[i][j] = grid[i][j] + max(first, second);
		}
		
	}
	
	vector<int> findWays(vector<vector<int>> & grid) {
		int ans = 0;
		
		int n = grid.size();
		int m = grid[0].size();
		
		// time => O(n^2)
		// space => O(n^2)
		
		vector<vector<int>> dp1(n + 1, vector<int>(m + 1, -1));
		vector<vector<int>> dp2(n + 1, vector<int>(m + 1, -1));
		
		int number_of_paths = solve1(0, 0, grid, dp1) % mod;
		int maxSum_of_validPath = solve2(0, 0, grid, dp2);
		
		if (maxSum_of_validPath < 0) {
			maxSum_of_validPath = 0;
		}
		
		return {number_of_paths, maxSum_of_validPath};
	}
};
