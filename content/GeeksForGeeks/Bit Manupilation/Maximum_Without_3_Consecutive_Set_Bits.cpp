class Solution {
	public:
	int maxValue(int n) {
		int ans = n;
		
		// O(1)
		// O(1)
		for (int i = 31 ; i >= 2; i--) {
			
			if ((ans & (1u << i)) && (ans&(1u << i - 1)) && (ans & (1u << i - 2))) {
				
				ans = ans & (~(1u << i - 2)); // 1 -> 0 => ~1 -> 0
			}
		}
		
		return ans;
	}
};
