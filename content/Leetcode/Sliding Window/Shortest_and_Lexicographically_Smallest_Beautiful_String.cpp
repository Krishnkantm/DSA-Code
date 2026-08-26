class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string str = "";
        //time => O(n)
        //space => O(1)
      
        int n = s.size();

        int i = 0;
        int j = 0;
        int ones = 0;

        while (j < n) {
            if (s[j] == '1') {
                ones++;
            }

            while (ones == k) {
                if (str == "" || (str.size() > (j - i + 1))) {
                    str = s.substr(i, j - i + 1);
                } else if (str.size() == (j - i + 1)) {
                    str = min(str, s.substr(i, j - i + 1));
                }

                if (s[i] == '1') {
                    ones--;
                }

                i++;
            }
            j++;
        }

        return str;
    }
};
