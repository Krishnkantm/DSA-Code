class Solution {
	public:
	bool solve(int index, vector<int>& arr, vector<int>& track, int n) {
		// base case
		if (index < 0 || index >= n) {
			return true;
		}
		
		if (arr[index] == 0) {
			return false;
		}
		
		if (track[index] == 1) {
			return false;
		}
		
		if (track[index] == 2) {
			return true;
		}
		
		if (track[index] == 3) {
			return false;
		}
		
		track[index] = 1;
		
		int good = solve(index + arr[index], arr, track, n);
		
		track[index] = good ? 2 : 3;
		
		return good;
	}
	
	int goodIndices(vector<int> &arr) {
		int n = arr.size();
		
		vector<int> track(n, 0);
		
		int good = 0;
		
		// time ->  O(n)
		// space -> O(n)
		for (int i = 0; i<n; i++) {
			
			if (solve(i, arr, track, n)) {
				good++;
			}
		}
		
		return good;
	}
};
