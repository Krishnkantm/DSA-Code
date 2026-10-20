class Solution {
	public:
	vector<int> lexicographicallyLargest(vector<int> &arr) {
		int n = arr.size();
		
		int i = 0;
		
		// O(n)
		while (i<n) {
			
			int j = i;
			
			while (j < n && arr[i] % 2 == arr[j] % 2) {
				j++;
			}
			
			// O(nlong n)
			sort(arr.begin() + i, arr.begin() + j, greater<int>());
			
			i = j;
		}
		
		// o(nlong n)
		// O(1)
		
		return arr;
	}
};
