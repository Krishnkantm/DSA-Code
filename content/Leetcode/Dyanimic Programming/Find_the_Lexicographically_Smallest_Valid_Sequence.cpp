#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> right_Suffix_length(n, 0);

        // space complexity => O(n)
        // time complexity =>  o(n+m)
        int j = m - 1;
        int length = 0;

        for (int i = n - 1; i >= 0; i--) {
            right_Suffix_length[i] = length;

            if (j >= 0 && word1[i] == word2[j]) {
                length++;
                j--;
            }
        }

        vector<int> ans;
        j = 0;

        bool change = true;

        // o(n) + O(m)
        for (int i = 0; i < n && j < m; i++) {
            // both match character
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } // both character not match
            else if (change && right_Suffix_length[i] >= m - j - 1) {
                ans.push_back(i);
                change = false;
                j++;
            }
        }

        if (j < m) {
            return {};
        }

        return ans;
    }
};