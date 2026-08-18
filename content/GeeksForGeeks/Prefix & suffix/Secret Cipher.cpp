class Solution {
	public:
	void fillLPS(vector<int>& lps, string& str) {
		int len = 0;
		int i = 1;
		
		int n = str.size();
		
		// Time  => O(n)
		// space => O(n)
		
		// o(n)
		while (i<n) {
			
			// match
			if (str[i] == str[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else {
				if (0 == len) {
					lps[i] = 0;
					i++;
				}
				else {
					len = lps[len - 1];
				}
			}
		}
	}
	
	string compress(string &s) {
		int n = s.size();
		
		vector<int> lps(n, 0); // )(n)
		
		fillLPS(lps, s);
		
		stack<char> st; // 0(n)
		
		// O(n)
		for (int i = n - 1; i>0; i--) {
			int len = i + 1;
			
			if (len % 2 == 1) {
				st.push(s[i]);
				continue;
			}
			
			int prefixLength = len - lps[i];
			
			if ((lps[i]*2 >= len) && (len % prefixLength == 0) && ((len / prefixLength)) % 2 == 0) {
				st.push('*');
				i = (len/2);
			}
			else {
				st.push(s[i]);
			}
		}
		
		string result = "";
		
		result.push_back(s[0]);
		
		while (!st.empty()) {
			result.push_back(st.top());
			st.pop();
		}
		
		return result;
	}
};
