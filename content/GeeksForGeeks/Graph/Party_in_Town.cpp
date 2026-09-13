class Solution {
	public:
	pair<int, int> bfs(int start, vector<vector<int>> & adj) {
		
		int n = adj.size();
		
		int endNode = start;
		int maxDistance = 0;
		
		queue<pair<int, int>> q;
		
		q.push({0, start});
		
		vector<int> distance(n + 1, INT_MAX);
		distance[start] = 0;
		
		// bfs
		while (!q.empty()) {
			int curr_distance = q.front().first;
			int node = q.front().second;
			
			q.pop();
			
			// nbr traverse
			
			for (auto &nbr : adj[node - 1]) {
				
				if (distance[nbr] > curr_distance + 1) {
					distance[nbr] = curr_distance + 1;
					q.push({curr_distance + 1, nbr});
					
					if (maxDistance < distance[nbr]) {
						maxDistance = distance[nbr];
						endNode = nbr;
					}
				}
			}
		}
		
		return {endNode, maxDistance};
		
	}
	
	int partyHouse(vector<vector<int>> &adj) {
		int n = adj.size();
		
		// O(n)
		pair<int, int> first = bfs(1, adj); // node
		int node = first.first;
		
		// O(n)
		pair<int, int> second = bfs(node, adj); // distace
		
		int diameter = second.second;
		
		// time => O(n)
		// space => O(n)
		
		return (diameter + 1)/2;
	}
};
