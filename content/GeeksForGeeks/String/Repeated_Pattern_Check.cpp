class Solution {
	public:
	bool findPattern(string& s) {
		int n = s.size();
		
		if (s[0] == 'y')
			return false;
		
		int i = 0;
		
		// time -> O(n)
		// space ->  O(1)
		while (i<n) {
			
			if (s[i] == 'y')
				return false;
			
			int count_x = 0;
			int count_y = 0;
			
			// count x
			while (i<n && s[i] == 'x') {
				count_x++;
				i++;
			}
			
			if (i >= n)
				return false;
			
			// count y
			while ((i<n && s[i] == 'y') && (count_y < count_x)) {
				count_y++;
				i++;
			}
			
			if (count_x != count_y)
				return false;
		}
		
		return true;
	}
};
