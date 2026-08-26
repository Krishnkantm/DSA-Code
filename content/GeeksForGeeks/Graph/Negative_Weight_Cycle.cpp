class Solution {
	public:
	bool isNegativeWeightCycle(int V, vector<vector<int>> & edges) {
		vector<long long> dist(V, 0);
		
		// time => O(V*E)
		// space => O(V)
		
		// step 1 n-1 times distance formula
		for (int i = 0; i<V - 1; i++) {
			bool check = true;
			
			// all edges
			for (auto e : edges) {
				int u = e[0];
				int v = e[1];
				int wt = e[2];
				
				if (dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
					check = false;
				}
			}
			
			if (check) {
				break;
			}
		}
		
		// step 2, 1 more time
		for (auto e : edges) {
			int u = e[0];
			int v = e[1];
			int wt = e[2];
			
			if (dist[u] + wt < dist[v]) {
				return true;
			}
		}
		
		return false;
	}
};
