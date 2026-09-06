class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // base case
        if (j >= t.size()) {
            return 1;
        }

        // base 2
        if (i >= s.size() && j < t.size()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int include = 0;

        if (s[i] == t[j]) {
            include = solve(i + 1, j + 1, s, t, dp);
        }

        int exclude = solve(i + 1, j, s, t, dp);

        return dp[i][j] = (include + exclude);
    }

    int bottomUp(string& s, string& t) {
        int n = s.size();
        int m = t.size();

        vector<int> pre(m + 1, 0);
        vector<int> curr(m + 1, 0);

        // time  =>  O(n*m)
        // space => O(m)

        for (int i = 1; i <= n; i++) {
            pre[0] = 1;
            curr[0] = 1;

            for (int j = 1; j <= m; j++) {

                int include = 0;

                if (s[i - 1] == t[j - 1]) {
                    include = pre[j - 1];
                }

                int exclude = pre[j];

                curr[j] = include * 1LL + exclude * 1LL;
            }

            pre = curr;
        }

        return curr[m];
    }
    int numDistinct(string s, string t) { return bottomUp(s, t); }
};
