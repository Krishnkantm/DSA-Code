class Solution {
public:
    // O(n)
    int minimumInvalidParanthesis(string& s) {

        int balance = 0;
        int invalidParanthesis = 0;

        for (char ch : s) {

            if ('(' == ch) { // if(a = 5) -> (5 == a)
                balance++;
            } else if (')' == ch) {
                balance--;

                if (balance < 0) {
                    invalidParanthesis++;
                    balance = 0;
                }
            }
        }

        invalidParanthesis += balance;

        return invalidParanthesis;
    }

    // O(n) + (2^n) = >O(2^n) + O(n)
    void solve(int index, string& s, string& str, int balance, int invalid,
               unordered_set<string>& st) {

        // base case
        if (index >= s.size()) {

            if (balance == 0 && invalid == 0) {
                st.insert(str);
            }

            return;
        }

        // case 2
        if (balance < 0) {
            return;
        }

        // case3
        if (invalid > s.size() - index) {
            return;
        }

        // exclude
        if (s[index] == '(' || s[index] == ')') {
            solve(index + 1, s, str, balance, invalid - 1, st);
        }

        // include
        int curr_count = 0;

        if (s[index] == '(') {
            curr_count++;
        } else if (s[index] == ')') {
            curr_count--;
        }

        str.push_back(s[index]);
        solve(index + 1, s, str, balance + curr_count, invalid, st);
        str.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int invalidCount = minimumInvalidParanthesis(s);

        unordered_set<string> st;

        string str = "";
        solve(0, s, str, 0, invalidCount, st);

        vector<string> v(st.begin(), st.end()); // O(n)

        // time -> O(n 2^n)
        // space -> (n)

        if (v.empty()) {
            v.push_back("");
        }

        return v;
    }
};
