class Solution {
	public:
	int mod = 1000000007;
	
	long long power(long long a, long long b) {
		
		// base case
		if (b == 0)
			return 1;
		
		long long result = 1;
		
		while (b > 0) {
			
			// power is odd
			if (b % 2) {
				result = (result * a) % mod;
			}
			
			a = (a*a) % mod;
			
			b /= 2;
		}
		
		return result;
	}
	
	int subsequenceSum(string &s) {
		int n = s.size();
		
		long long ans = 0;
		long long times = power(2, 1LL*(n - 1)); // O(long n)
		
		// O(n)
		for (int i = 0; i<n; i++) {
			int digit = s[i] - '0';
			
			ans = (ans + (digit * times) % mod) % mod;
		}
		
		// time -> O(n) + O(log n) => O(n)
		// space -> O(1)
		
		return ans;
	}
};
