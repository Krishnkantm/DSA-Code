class Solution {
	public:
	int minOperation(int n) {
		int opr = 0;
		
		// o(long n)
		// o(1)
		
		while (n > 0) {
			
			if (n % 2 == 0) {
				n /= 2;
				opr++;
			}
			else {
				n--;
				opr++;
			}
		}
		
		return opr;
	}
};
