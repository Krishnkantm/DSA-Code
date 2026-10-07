class Solution {
public:
    long long solve(int index, int parity, int deletion, vector<int>& nums,
                    vector<vector<vector<long long>>>& dp) {
        // base case
        if (index >= nums.size())
            return 0;

        if (dp[index][parity][deletion] != LLONG_MIN) {
            return dp[index][parity][deletion];
        }

        long long value = 0;
        long long ans = 0;

        if (parity == 0) {
            value = 1LL * nums[index];
        } else {
            value = -1LL * nums[index];
        }

        int nextParity = 1 - parity;

        // include
        long long include =
            value + solve(index + 1, nextParity, deletion, nums, dp);
        ans = max(ans, include);

        // exclude
        if (deletion == 0) {
            long long exclude =
                solve(index + 1, parity, deletion + 1, nums, dp);
            ans = max(ans, exclude);
        }

        return dp[index][parity][deletion] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(2, vector<long long>(2, LLONG_MIN)));

        long long ans = LLONG_MIN;

        // O(n)
        // O(2*2*n) = >O(n)
        for (int i = 0; i < n; i++) {

            long long curr = nums[i] + solve(i + 1, 1, 0, nums, dp);
            ans = max(ans, curr);
        }

        return ans;
    }
};
