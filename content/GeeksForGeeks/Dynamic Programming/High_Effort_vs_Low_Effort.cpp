class Solution {
	public:
	int maxTask(vector<int>& h, vector<int>& l) {
		int n = h.size();
		
		// time => o(n)
		// space => O(1)
		
		// edges only we have one element
		int pre1 = 0;
		int pre2 = l[0];
		int pre3 = h[0];
		
		for (int i = 1; i<n; i++) {
			
			int curr1 = max({pre1, pre2, pre3});
			int curr2 = l[i] + max({pre1, pre2, pre3});
			int curr3 = pre1 + h[i];
			
			pre1 = curr1;
			pre2 = curr2;
			pre3 = curr3;
		}
		
		return max({pre1, pre2, pre3});
		
	}
};
