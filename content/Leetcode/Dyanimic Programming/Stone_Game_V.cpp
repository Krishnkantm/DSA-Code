class Solution {
public:
    int solve(int l, int r, vector<long long>& prefixSum, int& ans,
              vector<vector<long long>>& dp) {
        // base case
        if (l >= r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int result = 0;

        for (int k = l; k < r; k++) {
            int left_sum =
                (l - 1 >= 0) ? prefixSum[k] - prefixSum[l - 1] : prefixSum[k];

            int newl = k + 1;
            int right_sum = (newl - 1 >= 0) ? prefixSum[r] - prefixSum[newl - 1]
                                            : prefixSum[r];

            // 1
            if (left_sum > right_sum) {
                result =
                    max(result, right_sum + solve(newl, r, prefixSum, ans, dp));
            } else if (left_sum < right_sum) {
                result =
                    max(result, left_sum + solve(l, k, prefixSum, ans, dp));
            } else {
                result =
                    max({result, left_sum + solve(l, k, prefixSum, ans, dp),
                         right_sum + solve(newl, r, prefixSum, ans, dp)});
            }
        }

        ans = max(ans, result);
        return dp[l][r] = result;
    }

    long long BottomUp(vector<long long>& prefixSum) {
        int n = prefixSum.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {

                long long result = 0;

                for (int k = l; k < r; k++) {
                    long long left_sum = (l - 1 >= 0)
                                             ? prefixSum[k] - prefixSum[l - 1]
                                             : prefixSum[k];

                    long long newl = k + 1;
                    long long right_sum =
                        (newl - 1 >= 0) ? prefixSum[r] - prefixSum[newl - 1]
                                        : prefixSum[r];

                    // 1
                    if (left_sum > right_sum) {
                        result = max(result, right_sum + dp[newl][r]);

                    } else if (left_sum < right_sum) {
                        result = max(result, left_sum + dp[l][k]);
                    } else {
                        result = max({result, left_sum + dp[l][k],
                                      right_sum + dp[newl][r]});
                    }
                }

                dp[l][r] = result;
            }
        }

        return dp[0][n - 1]; // [0 -> n]
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<long long> prefixSum(n, 0);
        prefixSum[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = 1LL * prefixSum[i - 1] + 1LL * stoneValue[i];
        }

        int ans = 0;

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        // solve(0, n - 1, prefixSum, ans, dp);
        return (int)BottomUp(prefixSum);
    }
};
