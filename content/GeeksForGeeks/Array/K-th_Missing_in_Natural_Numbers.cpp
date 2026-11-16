class Solution {
	public:
	int findKthSmall(vector<int>& arr, int k) {
		int pre = 0;
		
		// time -> O(n log n)
		// space -> O (1)
		
		int total = 0;
		int index = -1;
		
		int n = arr.size();
		
		// sort
		sort(arr.begin(), arr.end()); // o(nlong n)
		
		// O(n)
		for (int i = 0; i<n; i++) {
			int curr_valid_element = (arr[i] - pre - 1);
			
			if (total + curr_valid_element >= k)
				break;
			
			pre = arr[i];
			index = i;
			total += curr_valid_element;
		}
		
		// edge case
		if (index == -1) {
			return pre + k;
		}
		
		int remain = k - total;
		int element = arr[index];
		
		return element + remain;
	}
};
