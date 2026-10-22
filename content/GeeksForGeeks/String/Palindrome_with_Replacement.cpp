class Solution {
	public:
	int minimumSum(string &s) {
		int n = s.size();
		
		// step1 check fixed character
		
		int i = 0;
		int j = n - 1;
		
		int ans = 0;
		
		// O(n)
		while (i<j) {
			
			if ((s[i] != '?' && s[j] != '?') && (s[i] != s[j])) {
				return - 1;
			}
			else if (s[i] == '?' && s[j] != '?') {
				s[i] = s[j];
			}
			else if (s[i] != '?' && s[j] == '?') {
				s[j] = s[i];
			}
			i++;
			j--;
		}
		
		int mid = n / 2;
		i = 0, j = 0;
		
		// left
		while (i<mid && s[i] == '?')
			i++;
		
		j = i + 1;
		
		while (i<mid) {
			
			while (j<mid && s[j] == '?')
				j++;
			
			if (j >= mid) {
				break;
			}
			
			ans = ans + abs(s[i] - s[j]);
			
			i = j;
			j++;
		}
		
		ans = 2*ans;
		
		// odd
		if (n % 2 != 0) {
			if (s[mid] != '?') {
				i = mid - 1;
				
				while (i >= 0 && s[i] == '?') {
					i--;
				}
				
				if (i >= 0) {
					ans += abs(s[i] - s[mid]);
				}
			}
		}
		
		// time -> O(n)
		// space -> O(1)
		
		return ans;
	}
};
