class Solution {
	public:
	vector<int> largestSquare(vector<vector<int>> & mat, vector<vector<int>> & queries,
	int k) {
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> prefixSum(n, vector<int>(m, 0));
		
		// O (n*m)
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				
				int left_part = (j - 1 >= 0) ? prefixSum[i][j - 1] : 0;
				int upper_part = (i - 1 >= 0) ? prefixSum[i - 1][j] : 0;
				int diagonal_part = (i - 1 >= 0 && j - 1 >= 0) ? prefixSum[i - 1][j - 1] : 0;
				
				prefixSum[i][j] = (left_part + upper_part) - diagonal_part + mat[i][j];
			}
		}
		
		vector<int> ans;
		
		// o(size)
		
		for (auto &p : queries) {
			int r = p[0];
			int c = p[1];
			
			int r1 = r;
			int c1 = c;
			
			int r2 = r;
			int c2 = c;
			
			int length = -1;
			
			while ((r1 >= 0 && c1 >= 0) && (r2 < n && c2 < m)) {
				int left_part = (c1 - 1 >= 0) ? prefixSum[r2][c1 - 1] : 0;
				int upper_part = (r1 - 1 >= 0) ? prefixSum[r1 - 1][c2] : 0;
				
				int diagonal_part = (r1 - 1 >= 0 && c1 - 1 >= 0) ? prefixSum[r1 - 1][c1 - 1] : 0;
				
				int sum = (prefixSum[r2][c2] - (left_part + upper_part)) + diagonal_part;
				
				if (sum <= k) {
					length = max(length, r2 - r1 + 1);
				}
				
				r1--;
				c1--;
				
				r2++;
				c2++;
			}
			
			ans.push_back(length);
		}
		
		// timecomplexity => O(n*m) + (size)
		// space complexiy => o(n*m) + size
		
		return ans;
		
	}
};
