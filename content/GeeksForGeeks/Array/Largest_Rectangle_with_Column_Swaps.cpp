class Solution {
	public:
	int maxArea(vector<vector<int>> & mat) {
		int n = mat.size();
		
		int m = mat[0].size();
		
		vector<int> pre(m, 0);
		vector<int> curr(m, 0);
		
		int ans = 0;
		
		// time => O(n * (m + m+q))
		// space => (m*n)
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				
				if (mat[i][j] == 0) {
					curr[j] = 0;
				}
				else {
					curr[j] = pre[j] + mat[i][j];
				}
			}
			
			vector<int> temp;
			
			for (int j = 0; j<m; j++) {
				if (curr[j] > 0) {
					temp.push_back(curr[j]);
				}
			}
			
			int size = temp.size();
			
			if (size == 0) {
				pre = curr;
				continue;
			}
			
			sort(temp.begin(), temp.end());
			
			for (int p = 0; p<temp.size(); p++) {
				int length = temp[p];
				int breath = size - p;
				
				ans = max(ans, length * breath);
			}
			
			pre = curr;
		}
		
		return ans;
	}
};
