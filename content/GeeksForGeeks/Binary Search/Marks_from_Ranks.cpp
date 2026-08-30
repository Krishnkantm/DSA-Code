class Solution {
	public:
	int binarySearch(int start, int end, vector<int>& prefix, int rank) {
		while (start < end) {
			int mid = start + (end - start)/2;
			
			if (prefix[mid] < rank) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}
		
		return start;
	}
	
	vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
		int n = l.size();
		
		vector<int> prefix(n, 0);
		prefix[0] = r[0] - l[0] + 1;
		
		// O(n) + O(q*O(longn))=> n + q long n
		// O(n) + O(n) = > O(n)
		for (int i = 1; i<n; i++) {
			prefix[i] = prefix[i - 1] + (r[i]-l[i]+1);
		}
		
		vector<int> ans;
		
		for (int i = 0; i<rank.size(); i++) {
			int idx = binarySearch(0, n - 1, prefix, rank[i]);
			
			int diff = prefix[idx] - rank[i];
			ans.push_back(r[idx] - diff);
		}
		
		return ans;
	}
};
