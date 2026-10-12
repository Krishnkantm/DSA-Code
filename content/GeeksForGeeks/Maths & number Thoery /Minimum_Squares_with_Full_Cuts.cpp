class Solution {
	public:
	int minSquares(int n, int m) {
		int ans = 0;
		
		// time -> log(min(n,m))
		// space -> O(1)
		
		while (n > 0 && m > 0) {
			
			if (n > m) {
				swap(n, m);
			}
			
			int d = m/n;
			
			ans += d;
			
			m = m - (n*d);
		}
		
		return ans;
	}
};
