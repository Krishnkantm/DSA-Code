class Solution {
	public:
	int sameMod(vector<int> &arr) {
		int n = arr.size();
		
		bool flag = true;
		
		// O(n)
		for (int i = 1; i<n; i++) {
			if (arr[i] != arr[0]) {
				flag = false;
				break;
			}
		}
		
		if (flag)
			return - 1;
		
		int g = 0;
		
		// O(n)
		for (int i = 1; i<n; i++) {
			g = __gcd(g, abs(arr[0] - arr[i]));
		}
		
		int ans = 0;
		
		// O(sqrt(g))
		for (int i = 1; i*i <= g; i++) {
			
			if (g % i == 0) {
				ans++;
				
				if ((g/i) != i) {
					ans++;
				}
			}
		}
		
		// time => O(n) + O(n) + O(sqrt(g))
		// space => O(1)
		
		return ans;
	}
};
