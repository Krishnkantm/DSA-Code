class Solution {
public:
    bool solve(string curr, string& s, string& target, int index,
               vector<int>& freq, bool greater, string& result) {

        // base case
        if (index >= target.size()) {
            if (greater) {
                result = curr;
                return true;
            }

            return false;
        }

        // a -> z
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;

            if (greater == false && ch < target[index]) {
                continue;
            }

            bool isValid = greater || ch > target[index];

            curr.push_back(ch);
            freq[ch - 'a']--;

            if (solve(curr, s, target, index + 1, freq, isValid, result)) {
                return true;
            }

            // backtrack
            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        string result = "";

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        solve("", s, target, 0, freq, false, result);

        return result;
    }
};
