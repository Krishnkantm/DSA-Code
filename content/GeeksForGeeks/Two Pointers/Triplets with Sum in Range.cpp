class Solution {
	public:
	int solve(vector<int>& arr, int target) {
		int count = 0;
		int n = arr.size();
		
		// time => 0(N^2)
		// space => O(1)
		
		for (int i = 0; i<n; i++) {
			int j = i + 1;
			int k = n - 1;
			
			while (j<k) {
				while (k>j && (arr[i] + arr[j] + arr[k]) > target) {
					k--;
				}
				
				if (j >= k)
					break;
				else {
					count += (k - j);
				}
				j++;
			}
		}
		
		return count;
	}
	int countTriplets(vector<int> &arr, int l, int r) {
		sort(arr.begin(), arr.end());
		
		return solve(arr, r) - solve(arr, l - 1);
	}
};
