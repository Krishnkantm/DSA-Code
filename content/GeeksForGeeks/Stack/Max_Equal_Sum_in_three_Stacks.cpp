class Solution {
	public:
	void findSum(vector<int>& v, int& sum) {
		
		for (int i = 0; i<v.size(); i++) {
			sum += v[i];
		}
	}
	
	int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
		int n1 = s1.size();
		int n2 = s2.size();
		int n3 = s3.size();
		
		int sum1 = 0, sum2 = 0, sum3 = 0;
		
		findSum(s1, sum1);
		findSum(s2, sum2);
		findSum(s3, sum3);
		
		int top1 = 0, top2 = 0, top3 = 0;
		
		while (true) {
			
			if (top1 == n1 || top2 == n2 || top3 == n3) {
				return 0;
			}
			
			if (sum1 == sum2 && sum2 == sum3) {
				return sum1;
			}
			
			if (sum1 >= sum2 && sum1 >= sum3) {
				sum1 -= s1[top1++];
			}
			else if (sum2 >= sum1 && sum2 >= sum3) {
				sum2 -= s2[top2++];
			}
			else if (sum3 >= sum1 && sum3 >= sum2) {
				sum3 -= s3[top3++];
			}
		}
		
		// time -> O(n1 + n2 + n3) + O(max(n1,n2,n3)) => O(n1 + n2 + n3)
		// space -> O(1)
		
		return 0;
	}
};

