class Solution {
public:
    bool solve(int index, string& s, int balance, vector<vector<int>>& dp) {
        // base case
        if (index >= s.size()) {
            return balance == 0;
        }

        if (balance < 0)
            return false;

        if (dp[index][balance] != -1) {
            return dp[index][balance];
        }

        bool ans = false;

        if (s[index] == '(') {
            ans = solve(index + 1, s, balance + 1, dp);
        } else if (s[index] == ')') {
            ans = solve(index + 1, s, balance - 1, dp);
        } else {
            ans = (solve(index + 1, s, balance + 1, dp) ||
                   (solve(index + 1, s, balance - 1, dp) ||
                    solve(index + 1, s, balance, dp)));
        }

        return dp[index][balance] = ans;
    }

    bool bottomUp(string& s) {
        int n = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[n][0] = true; // base case

        for (int index = n - 1; index >= 0; index--) {
            for (int balance = 0; balance <= n; balance++) {

                bool ans = false;
                if (s[index] == '(') {

                    if (balance + 1 <= n) {
                        ans = dp[index + 1][balance + 1];
                    }

                } else if (s[index] == ')') {

                    if (balance > 0) {
                        ans = dp[index + 1][balance - 1];
                    }

                } else {
                    bool open = false;
                    bool closing = false;
                    bool empty = false;

                    if (balance + 1 <= n) {
                        open = dp[index + 1][balance + 1];
                    }

                    if (balance > 0) {
                        closing = dp[index + 1][balance - 1];
                    }

                    empty = dp[index + 1][balance];

                    ans = (open || (closing || empty));
                }

                dp[index][balance] = ans;
            }
        }

        return dp[0][0];
    }

    bool checkValidString(string s) {
        // solve(0,s,0);
        //  bottomUp(s);

        stack<int> brackets;
        stack<int> stars;

        int n = s.size();

        // O(n)
        //  O(n)
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                brackets.push(i);
            } else if (s[i] == ')') {

                if (!brackets.empty()) {
                    brackets.pop();
                } else if (!stars.empty() && stars.top() < i) {
                    stars.pop();
                } else {
                    return false;
                }
            } else {
                stars.push(i);
            }
        }

        while (!brackets.empty() && !stars.empty()) {

            if (brackets.top() < stars.top()) {
                brackets.pop();
                stars.pop();
            } else {
                return false;
            }
        }

        if (brackets.empty())
            return true;

        return false;
    }
};
