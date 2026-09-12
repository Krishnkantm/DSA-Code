class Solution {
	public:
	int maxProduct(vector<int> &arr, int k) {
		int n = arr.size();
		
		sort(arr.rbegin(), arr.rend());
		
		// case 1
		if (arr[0] == 0 && (k&1)) {
			return 0;
		}
		
		// case 2
		
		// time => O(nlongn)
		// space => (1)
		if (arr[0] <= 0 && (k&1)) {
			int product = 1;
			
			for (int i = 0; i<k; i++) {
				product *= arr[i];
			}
			
			return product;
		}
		
		// case 3 k odd or arr=> +,-
		int left = 0;
		int right = n - 1;
		int ans = 1;
		
		while ((k&1)) {
			ans *= arr[left];
			left++;
			k--;
		}
		
		k = k/2;
		
		for (int i = 0; i<k; i++) {
			int leftProduct = arr[left] * arr[left + 1];
			int rightProduct = arr[right] * arr[right - 1];
			
			if (leftProduct > rightProduct) {
				ans *= leftProduct;
				left += 2;
			}
			else {
				ans *= rightProduct;
				right -= 2;
			}
		}
		
		return ans;
	}
};
