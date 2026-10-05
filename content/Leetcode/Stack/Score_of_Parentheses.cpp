class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st; // O(n)
        st.push(0);

        // time -> o(n)
        // space -> O(n)
        for (char ch : s) {

            if (ch == '(') {
                st.push(0);
            } else {
                int curr_score = st.top();
                st.pop();

                if (curr_score == 0) {
                    curr_score = 1;
                } else {
                    curr_score *= 2;
                }

                st.top() += curr_score;
            }
        }

        int ans = st.top();

        return ans;
    }
};
