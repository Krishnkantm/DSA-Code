class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        stack<int> st;
        int ans = 0;

        st.push(-1); // O(n)

        // o(n)
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                    continue;
                }

                int length = i - st.top();
                ans = max(ans, length);
            }
        }

        // t => O(n)
        // s => O(n)

        return ans;
    }
};
