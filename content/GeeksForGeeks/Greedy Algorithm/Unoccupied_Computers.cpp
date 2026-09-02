class Solution {
	public:
	int solve(int n, string s) {
		vector<int> freq(26, 0);
		
		int computer = n;
		int ans = 0;
		
		// time  =>(m) number of character in string
		// space => (1)
		for (char ch : s) {
			
			if (freq[ch] == 0) {
				freq[ch]++;
				
				if (computer > 0) {
					freq[ch]++;
					computer--;
				}
				else {
					ans++;
				}
			}
			else if (freq[ch] == 2) {
				computer++;
				freq[ch] -= 2;
			}
			else if (freq[ch] == 1) {
				freq[ch]--;
			}
		}
		
		return ans;
	}
};
