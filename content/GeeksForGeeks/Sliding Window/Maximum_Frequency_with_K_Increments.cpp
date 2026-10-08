class Solution {
	public:
	int maxFrequency(vector<int>& arr, int k) {
		sort(arr.begin(), arr.end());
		
		int n = arr.size();
		
		int left = 0;
		int ans = 1;
		
		int windowSum = 0;
		
		// o(n)
		// O(1)
		for (int right = 0; right<n; right++) {
			windowSum += arr[right];
			
			while (1LL*(arr[right]*(right - left + 1)) - windowSum > k) {
				windowSum -= arr[left];
				left++;
			}
			
			ans = max(ans, right - left + 1);
		}
		
		return ans;
	}
};
