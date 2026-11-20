class Solution {
	public:
	int minFlips(string &s) {
		int n = s.size();
		
		int flip1 = 0;
		int flip2 = 0;
		
		// time -> O(n)
		// sapce -> O(1)
		
		for (int i = 0; i<n; i++) {
			
			if (i % 2 == 0) {
				
				if (s[i] == '0') {
					flip1++;
				}
				else {
					flip2++;
				}
			}
			else {
				if (s[i] == '1') {
					flip1++;
				}
				else {
					flip2++;
				}
			}
		}
		
		return min(flip1, flip2);
	}
};

