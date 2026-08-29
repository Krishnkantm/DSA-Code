class Solution {
	public:
	int mod = 1e9 + 7;
	
	int solve(int index, string& s, int n, int curr_reminder, bool track, vector<vector<vector<int>>>& dp) {
		// base case
		if (index >= s.size()) {
			if (curr_reminder == 0 && track == true) {
				return 1;
			}
			
			return 0;
		}
		
		if (dp[index][curr_reminder][track] != -1)
			return dp[index][curr_reminder][track];
		
		// 2 options
		int include = solve(index + 1, s, n, ((curr_reminder*10) + (s[index] - '0')) % n, true, dp) % mod;
		
		int exclude = solve(index + 1, s, n, curr_reminder, track, dp) % mod;
		
		return dp[index][curr_reminder][track] = (include + exclude) % mod;
	}
	
	// bottomUp
	int bottomUp(string& s, int n) {
	    int size = s.size();
	    
		vector<int> pre(n+1,0);
		vector<int> curr(n+1,0);
		
		//time => (s.size() * (n))
		//space =>  (n)
		
		for (int i = 0; i<s.size(); i++) {
		    
		    // handle exclude case
		    curr = pre;
		    
		    // single element also a subsequenct
		    int digit = s[i] - '0';
		    curr[digit % n]++;
		    
		    if(curr[digit % n] >= mod){
		        curr[digit % n] -= mod;
		    }
			
			for (int r = 0; r<n; r++) {
				int new_reminder = (r*10 + digit) % n;
				
				curr[new_reminder] += pre[r];
				
				if(curr[new_reminder] >= mod){
				    curr[new_reminder] -= mod;
				}
			}
			
			pre = curr;
		}
		
		return pre[0] % mod;
	}
	
	int countSubsequences(string& s, int n) {
	
	    return bottomUp(s,n) % mod;
	}
};
