class Solution {
	public:
	int x[8] = {-1, 0, -1, 1, 0, 1, -1, 1};
	int y[8] = {0, -1, 1, 0, 1, -1, -1, 1};
	
	bool find(vector<vector<char>> & mat, int i, int j, string& word) {
		int length = word.size();
		int m = mat.size();
		int n = mat[0].size();
		
		for (int d = 0; d<8; d++) {
			
			int k;
			
			int currRow = i + x[d];
			int currCol = j + y[d];
			
			for (k = 1; k<length; k++) {
				if (currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || mat[currRow][currCol] != word[k]) {
					break;
				}
				
				currRow += x[d];
				currCol += y[d];
			}
			
			if (k == length)
				return true;
		}
		
		return false;
	}
	
	vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
		int m = mat.size();
		int n = mat[0].size();
		
		vector<vector<int>> ans;
		
		///time => O(m*n*l)
		// space => O(1)
		
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				
				if (mat[i][j] != word[0])
					continue;
				
				if (find(mat, i, j, word)) {
					ans.push_back({i, j});
				}
			}
		}
		
		return ans;
	}
};
