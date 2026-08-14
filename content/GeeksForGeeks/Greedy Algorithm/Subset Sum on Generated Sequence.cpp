class Solution {
	public:
	typedef long long ll;
	
	bool isPossible(vector<int>& arr, int s, int x) {
		int n = arr.size();
		
		vector<ll> seq;
		
		seq.push_back(s*1LL);
		ll prefix = s*1LL;
		
		// tc => O(n)
		// sp => O(n)
		
		for (int i = 0; i<n; i++) {
			seq.push_back(prefix + 1LL*arr[i]);
			prefix = prefix + seq[seq.size() - 1];
		}
		
		ll target = x*1LL;
		
		for (int i = seq.size() - 1; i >= 0; i--) {
			if (target - seq[i] >= 0) {
				target -= seq[i];
			}
		}
		
		return target == 0;
		
	}
};
