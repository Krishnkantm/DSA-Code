class Solution {
	public:
	int dominantPairs(vector<int> &arr) {
		int n = arr.size();
		
		// O(n long n)
		// O(1)
		sort(arr.begin(), arr.begin() + (n/2));
		sort(arr.begin() + (n/2), arr.end());
		
		int ans = 0;
		
		int j = n/2;
		for (int i = 0; i<(n/2); i++) {
			
			while (j<n && arr[i] >= 5 * arr[j]) {
				j++;
			}
			
			ans += (j - (n/2));
		}
		
		return ans;
	}
};
