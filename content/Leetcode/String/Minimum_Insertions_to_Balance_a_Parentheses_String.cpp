class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int balance = 0;
        int ans = 0;

        int i = 0;

        // time ->O(n)
        // space -> o(1)
        while (i < n) {

            if (s[i] == '(') {
                balance++;
                i++;
            } else {

                if (i + 1 < n && s[i + 1] == ')') {
                    balance--;

                    if (balance < 0) {
                        ans++;
                        balance = 0;
                    }

                    i += 2;
                } else {
                    ans++;
                    balance--;

                    if (balance < 0) {
                        ans++;
                        balance = 0;
                    }

                    i++;
                }
            }
        }

        ans = ans + (balance * 2);

        return ans;
    }
};
