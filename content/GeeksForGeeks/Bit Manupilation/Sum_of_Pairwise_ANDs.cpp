class Solution {
	public:
	long long pairAndSum(vector<int> &arr) {
		int n = arr.size();
		
		vector<int> bits(32, 0);
		// tie => O(n)
		// space => O(32) => O(1)
		for (int i = 0; i<n; i++) {
			
			for (int bit = 0; bit<32; bit++) {
				
				if ((arr[i] & (1 << bit))) {
					bits[bit]++;
				}
			}
		}
		
		long long ans = 0;
		
		for (int i = 0; i<32; i++) {
			long long pairs = (long long)(bits[i] *1LL* (bits[i]-1)/2);
			ans = ans*1LL + pairs *1LL* (1 << i);
		}
		
		return ans;
		
	}
};
