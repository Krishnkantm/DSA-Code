class Solution {
	public:
	int maxFruits(vector<int>& arr, int m) {
		int n = arr.size();
		
		int sum = 0;
    //time => O(n + m)
    //space => O(1)
		
		// first window sum
		for (int i = 0; i<m; i++) {
			sum += arr[i];
		}
		
		int ans = sum;
		int left = 0;
		
		for (int right = m; right<m + n; right++) {
			// old element exclude
			sum -= arr[left];
			
			// new element add
			sum += arr[right % n];
			
			ans = max(ans, sum);
			left++;
		}
		
		return ans;
		
	}
};
