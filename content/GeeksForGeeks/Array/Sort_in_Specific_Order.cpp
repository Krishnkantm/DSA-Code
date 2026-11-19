class Solution {
	public:
	void sortIt(vector<int>& arr) {
		int n = arr.size();
		int i = 0, j = 0;
		int lastIndex = -1;
		
		while (i<n && j<n) {
			
			// step 1 we skip all odd element
			while (i<n && arr[i] % 2 == 1) {
				lastIndex = i;
				i++;
			}
			
			if (j < i)
				j = i + 1;
			
			// step 2 find odd element
			while (j<n && arr[j] % 2 == 0) {
				j++;
			}
			
			if (j<n) {
				swap(arr[i], arr[j]);
				lastIndex = i;
			}
			i++;
		}
		
		// time -> O(n log n)
		// space -> O(1)
		
		// all element are even
		if (lastIndex == -1) {
			sort(arr.begin(), arr.end());
		}
		else {
			sort(arr.begin(), arr.begin() + lastIndex + 1, greater<int>());
			sort(arr.begin() + lastIndex + 1, arr.end());
		}
	}
};
