class Solution {
	public:
	int minProd(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		
		int neg = 0;
		int n = arr.size();
		
		for (int i = 0; i<n; i++) {
			if (arr[i] < 0)
				neg++;
		}
		
		if (neg == 0) {
			return arr[0];
		}
		
		int ans = 1;
		
		if (neg %2 == 0) {
			neg--;
		}
		
		for (int i = 0; i<n; i++) {
			if (neg <= 0)
				break;
			ans *= arr[i];
			neg--;
		}
		
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] <= 0)
				break;
			ans *= arr[i];
		}
		
		// time => O(n) + O(nlongn) => O(nlogn)
		// space => O(1)
		
		return ans;
	}
};
