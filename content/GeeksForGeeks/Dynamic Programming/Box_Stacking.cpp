class Solution {
	public:
	static bool comp(vector<int>& a, vector<int>& b) {
		if (a[0] == b[0]) {
			if (a[1] == b[1]) {
				return a[2] > b[2];
			}
			else {
				return a[1] > b[1];
			}
		}
		
		return a[0] > b[0];
	}

  //time -> O(n^2)
  //space -> (n)
	int solve(int index, vector<vector<int>> & v, vector<int>& dp) {
		
		if (dp[index] != -1)
			return dp[index];
		
		int ans = v[index][2];
		
		for (int j = index + 1; j<v.size(); j++) {
			
			if (v[index][0] > v[j][0] && v[index][1] > v[j][1]) {
				ans = max(ans, v[index][2] + solve(j, v, dp));
			}
		}
		
		return dp[index] = ans;
	}
	
	int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
		int n = height.size();

    //time => O(n^2)
    //space => O(n)
		
		vector<vector<int>> v;
		
		for (int i = 0; i<n; i++) {
			int a = height[i];
			int b = width[i];
			int c = length[i];
			
			v.push_back({a, b, c});
			v.push_back({a, c, b});
			
			v.push_back({b, a, c});
			v.push_back({b, c, a});
			
			v.push_back({c, a, b});
			v.push_back({c, b, a});
		}
		
		sort(v.begin(), v.end(), comp);
		
		int ans = 0;
		n = v.size();
		
		vector<int> dp(n, 0);
		
		for (int i = v.size() - 1; i >= 0; i--) {
			
			dp[i] = v[i][2];
			
			for (int j = i + 1; j<v.size(); j++) {
				
				if (v[i][0] > v[j][0] && v[i][1] > v[j][1]) {
					dp[i] = max(dp[i], v[i][2] + dp[j]);
				}
			}
			
			ans = max(ans, dp[i]);
		}
		
		return ans;
	}
};
