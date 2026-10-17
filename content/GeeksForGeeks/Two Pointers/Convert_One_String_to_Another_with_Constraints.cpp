class Solution {
	public:
	bool isItPossible(string &s1, string &s2) {
		int n = s1.size();
		int m = s2.size();
		
		if (n != m)
			return false;
		
		int i = 0, j = 0;
		
		// time - O(n)
		// space - O(1)
		
		while (i<n || j < n) {
			
			// '#' skip
			while (i<n && s1[i] == '#')
				i++;
			while (j < n && s2[j] == '#')
				j++;
			
			if (i >= n || j >= n) {
				return (i == n && j == n);
			}
			
			if (s1[i] != s2[j]) {
				return false;
			}
			
			if (s1[i] == 'A' && i < j)
				return false;
			if (s1[i] == 'B' && i > j)
				return false;
			i++;
			j++;
		}
		
		return (i == n && j == n);
	}
};
