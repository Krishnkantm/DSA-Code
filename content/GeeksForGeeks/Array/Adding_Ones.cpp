class Solution {
	public:
	vector<int> update(int n, vector<int>& updates) {
		vector<int> arr(n, 0);
		
		int m = updates.size();
		
		// O(n)
		for (int i = 0; i<m; i++) {
			int index = updates[i];
			
			// step 1 arr[i] += value
			arr[index - 1] += 1; // O(1) -> difference array techinique
		}
		
		// prefix sum  O(n)
		for (int i = 1; i<n; i++) {
			arr[i] += arr[i - 1];
		}
		
		// time -> O(n)
		// space -> O(1)
		
		return arr;
	}
};
