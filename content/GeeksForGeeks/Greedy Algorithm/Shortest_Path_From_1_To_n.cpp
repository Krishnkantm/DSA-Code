class Solution {
	public:
	int minimumStep(int n) {
		int count = 0;
		
		// O(log n)
		while (n > 1) {
			
			if (n % 3 == 0) {
				n /= 3;
			}
			else {
				n--;
			}
			
			count++;
		}
		
		return count;
	}
};
