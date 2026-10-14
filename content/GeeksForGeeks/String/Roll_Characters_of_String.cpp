class Solution {
	public:
	string findRollOut(string& s, vector<int>& roll) {
		int n = s.size();
		
		vector<int> arr(n, 0);
		
		// O(m)
		for (int i = 0; i<roll.size(); i++) {
			int index = roll[i];
			
			arr[index - 1] += 1;
		}
		
		// suffix sum
		// O(n)
		for (int i = n - 2; i >= 0; i--) {
			arr[i] += arr[i + 1];
		}
		
		string str = "";
		
		// O(n)
		for (int i = 0; i<n; i++) {
			char ch = s[i];
			
			int position = ch - 'a';
			int next_char_index = (position + arr[i]) % 26;
			
			ch = 'a' + next_char_index;
			str.push_back(ch);
		}
		
		// time -> O(n) + O(m)
		// space -> O(n)
		
		return str;
	}
};
