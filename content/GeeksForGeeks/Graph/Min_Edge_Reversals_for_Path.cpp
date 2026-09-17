class Solution {
	public:
	int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
		unordered_map<int, vector<vector<int>> > adj;
		
		// o(m)
		for (auto &it : edges) {
			adj[it[0]].push_back({it[1], 0});
			
			adj[it[1]].push_back({it[0], 1});
		}
		
		deque<int> dq;
		
		dq.push_front(src); // cost 0
		
		vector<int> distance(n + 1, INT_MAX);
		
		distance[src] = 0;
		
		// (n)
		while (!dq.empty()) {
			int node = dq.front();
			dq.pop_front();
			
			for (auto &it : adj[node]) {
				int nbr = it[0];
				int manuall = it[1];
				
				int cost = (manuall == 1) ? 1 : 0;
				
				if (distance[nbr] > distance[node] + cost) {
					
					distance[nbr] = distance[node] + cost;
					
					if (cost == 1) {
						dq.push_back(nbr);
					}
					else {
						dq.push_front(nbr);
					}
				}
			}
		}
		
		// time => O(n + m)
		// space => (n + m)
		
		if (distance[dst] == INT_MAX)
			return - 1;
		return distance[dst];
	}
};
