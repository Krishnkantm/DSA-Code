class Solution {
	public:
	int minSubarraySum(vector<int> &arr) {
		int n = arr.size();
		
		int sum = 0;
		int ans = INT_MAX;
		
		// O(n)
		// O(1)
		for (int i = 0; i<n; i++) {
			sum = min(sum + arr[i], arr[i]);
			
			if (ans > sum) {
				ans = sum;
			}
		}
		
		return ans;
		
	}
};
