class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        int balance = 0;
        string result = "";

        // O(n)
        // O(1)
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {

                if (balance > 0) {
                    result += s[i];
                }
                balance++;
            } else {

                balance--;

                if (balance > 0) {
                    result += s[i];
                }
            }
        }

        return result;
    }
};
