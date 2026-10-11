class Solution {
	public:
	void mergeTwoParts(vector<int>& arr) {
		int n = arr.size();
		
		int breakPoint = 0;
		
		for (int i = 0; i<n; i++) {
			
			if (arr[i] > arr[i + 1]) {
				breakPoint = i + 1;
				break;
			}
		}
		
		if (breakPoint == 0)
			return;
		
		vector<int> temp(n);
		
		int index = 0;
		
		int i = 0;
		int j = breakPoint;
		
		while (i<breakPoint && j < n) {
			
			if (arr[i] < arr[j]) {
				temp[index++] = arr[i];
				i++;
			}
			else {
				temp[index++] = arr[j];
				j++;
			}
		}
		
		while (i < breakPoint) {
			temp[index++] = arr[i++];
		}
		
		while (j < n) {
			temp[index++] = arr[j++];
		}
		
		// temp -> arr
		
		arr = temp; // O(n)
		
	}
};
