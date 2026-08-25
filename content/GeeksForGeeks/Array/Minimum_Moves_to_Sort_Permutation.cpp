class Solution {
	public:
	int minMoves(vector<int>& arr) {
		int n = arr.size();
		
		//time=>O(n)
		//space =>O(n)
		
		vector<int> position(n + 1, 0);
		
		for (int i = 0; i<n; i++) {
			position[arr[i]] = i;
		}
		
		int maxi = 1;
		int length = 1;
		
		for (int value = 2; value <= n; value++) {
			if (position[value] > position[value - 1]) {
				length++;
				maxi = max(maxi, length);
			}
			else {
				length = 1;
			}
		}
		
		return (n - maxi);
	}
};
