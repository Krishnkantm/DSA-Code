class Solution {
	public:
	int countWithout(int n, int d) {
		vector<vector<int>> dp(2, vector<int>(2, 0));
		
		// base case
		for (int tight = 0; tight<2; tight++) {
			for (int start = 0; start<2; start++) {
				dp[tight][start] = start;
			}
		}
		
		string str = to_string(n);
		int length = str.size();
		
		for (int position = length - 1; position >= 0; position--) { // O(11)
			vector<vector<int>> new_dp(2, vector<int>(2, 0));
			
			for (int tight = 0; tight<2; tight++) { // O(2)
				for (int start = 0; start<2; start++) {// O(2)
					
					int limit = tight ? (str[position] - '0') : 9;
					int total = 0;
					
					for (int digit = 0; digit <= limit; digit++) {// O(9)
						int check_start = start || (digit != 0);
						
						if (check_start && digit == d) {
							continue;
						}
						
						int new_tight = tight && (digit == limit);
						total += dp[new_tight][check_start];
					}
					
					new_dp[tight][start] = total;
				}
			}
			dp = new_dp;
		}
		
		// time => O(1296) 10^9 => 1296 => 1o^2 => long n
		// space => O(tight*start) + (tight*start) => O(4) + O(4) => O(8)
		
		return dp[1][0];
	}
};
