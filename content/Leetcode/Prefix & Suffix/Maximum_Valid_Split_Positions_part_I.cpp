class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> arr;

        for (int i = 0; i < n; i++) {
            if (k != i) {
                arr.push_back(nums[i]);
            }
        }

        int m = arr.size();
        vector<int> prefix(m, 0);
        vector<int> suffix(m, 0);

        prefix[0] = arr[0];

        for (int i = 1; i < m; i++) {
            prefix[i] = __gcd(prefix[i - 1], arr[i]);
        }

        suffix[m - 1] = arr[m - 1];

        for (int i = m - 2; i >= 0; i--) {
            suffix[i] = __gcd(suffix[i + 1], arr[i]);
        }

        int ans = 0;

        for (int i = 0; i < m - 1; i++) {
            if (prefix[i] == suffix[i + 1]) {
                ans++;
            }
        }

        return ans;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        // case1
        ans = solve(nums, -1); // O(n)

        // case2
        // O(n*n)
        for (int i = 0; i < n; i++) {
            int curr = solve(nums, i);
            ans = max(curr, ans);
        }

        // time -> O(n^2)
        // space => O(n)

        return ans;
    }
};
