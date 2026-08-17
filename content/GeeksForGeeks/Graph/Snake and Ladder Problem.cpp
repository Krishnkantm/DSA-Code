class Solution {
	public:
	int bfs(vector<int>& power, int n) {
		
		queue<pair<int, int>> pq;
		
		pq.push({0, 1});
		
		vector<int> distance((n*n) + 1, INT_MAX);
		distance[1] = 0;
		
		while (!pq.empty()) {
			int cost = pq.front().first;
			int node = pq.front().second;
			pq.pop();
			
			if (node == (n*n)) {
				return distance[node];
			}
			
			for (int d = 1; d <= 6; d++) {
				int next_move = node + d;
				
				if (next_move > (n*n)) {
					break;
				}
				
				if (power[next_move] != -1) {
					if (distance[power[next_move]] > cost + 1) {
						distance[power[next_move]] = cost + 1;
						pq.push({cost + 1, power[next_move]});
					}
				}
				else {
					if (distance[next_move] > cost + 1) {
						distance[next_move] = cost + 1;
						pq.push({cost + 1, next_move});
					}
				}
			}
		}
		
		return INT_MAX;
	}
	
	int minThrows(int n, vector<int>& lad, vector<int>& sn) {
		int N = n*n;
		
		vector<int> power(N + 1, -1);
		
		// Time => O(n^2)
		// space => O(n^2)
		
		for (int i = 0; i<lad.size(); i += 2) {
			if (i + 1 >= lad.size())
				break;
			
			power[lad[i]] = lad[i + 1];
		}
		
		for (int i = 0; i<sn.size(); i += 2) {
			if (i + 1 >= sn.size())
				break;
			power[sn[i]] = sn[i + 1];
		}
		
		int ans = bfs(power, n);
		
		if (ans == INT_MAX)
			return - 1;
		
		return ans;
		
	}
};
