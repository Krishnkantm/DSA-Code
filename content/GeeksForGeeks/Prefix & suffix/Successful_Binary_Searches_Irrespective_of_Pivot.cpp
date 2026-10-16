class Solution {
	public:
	int countAlwaysFound(vector<int>& arr) {
		int n = arr.size();
		
		vector<int> prefixMax(n, 0);
		prefixMax[0] = arr[0];
		
		for (int i = 1; i<n; i++) {
			prefixMax[i] = max(prefixMax[i - 1], arr[i]);
		}
		
		vector<int> suffixMin(n, 0);
		suffixMin[n - 1] = arr[n - 1];
		
		for (int i = n - 2; i >= 0; i--) {
			suffixMin[i] = min(suffixMin[i + 1], arr[i]);
		}
		
		int count = 0;
		
		for (int i = 0; i<n; i++) {
			bool left = i == 0 || prefixMax[i - 1] < arr[i];
			bool right = i == n - 1 || suffixMin[i + 1] > arr[i];
			
			if (left && right) {
				count++;
			}
		}
		
		//time =>  O(n)
		//space =>  O(n)
		
		return count;
	}
};
