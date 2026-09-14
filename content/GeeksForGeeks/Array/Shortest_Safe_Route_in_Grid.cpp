class Solution {
	public:
	int shortestPath(vector<vector<int>> &mat) {
		int n = mat.size();
		int m = mat[0].size();
		
		vector<int> dirX = {0, 1, -1, 0};
		vector<int> dirY = {1, 0, 0, -1};
		
		// O(n*m)
		// step 1 : unsafe cell -1
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				
				if (mat[i][j] == 0) {
					for (int d = 0; d<4; d++) {
						int newRow = i + dirX[d];
						int newCol = j + dirY[d];
						
						if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mat[newRow][newCol] != 0) {
							mat[newRow][newCol] = -1;
						}
					}
					
				}
			}
		}
		
		// step 2:
		queue<pair<int, pair<int, int>> > q;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		
		// O(n)
		for (int i = 0; i<n; i++) {
			
			if (mat[i][0] == 1) {
				q.push({1, {i, 0}});
				visited[i][0] = true;
			}
		}
		
		// (n*m)
		while (!q.empty()) {
			int curr_steps = q.front().first;
			int r = q.front().second.first;
			int c = q.front().second.second;
			
			q.pop();
			
			// target
			if (c == m - 1) {
				return curr_steps;
			}
			
			// four direction try
			for (int d = 0; d<4; d++) {
				int newRow = r + dirX[d];
				int newCol = c + dirY[d];
				
				if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mat[newRow][newCol] == 1 && visited[newRow][newCol] == false) {
					q.push({curr_steps + 1, {newRow, newCol}});
					visited[newRow][newCol] = true;
				}
			}
		}
		
		// time => O(n*m)
		// space => O(n*m) + O(n*m) => O(n*m)
		
		return - 1;
		
	}
};
