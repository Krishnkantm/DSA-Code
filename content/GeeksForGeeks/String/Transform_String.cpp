class Solution {
	public:
	int getChar(char ch) {
		
		if (ch >= 'a' && ch <= 'z') {
			return (26 + (ch - 'a'));
		}
		else {
			return (ch - 'A');
		}
	}
	int transform(string &s1, string &s2) {
		
		int n = s1.size();
		int m = s2.size();
		
		// time => O(n)
		// space => O(1)
		
		if (n != m)
			return - 1;
		
		vector<int> freq(52, 0);
		
		for (int i = 0; i<n; i++) {
			int index = getChar(s1[i]);
			
			freq[index]++;
			
			index = getChar(s2[i]);
			freq[index]--;
		}
		
		for (int i = 0; i<52; i++) {
			if (freq[i] != 0) {
				return - 1;
			}
		}
		
		int i = n - 1;
		int j = m - 1;
		
		int result = 0;
		
		while (i >= 0 && j >= 0) {
			while (i >= 0 && s1[i] != s2[j]) {
				result++;
				i--;
			}
			
			i--;
			j--;
		}
		
		return result;
	}
};
