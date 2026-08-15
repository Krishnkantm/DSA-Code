class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int maxXor = 0;

        // time complexity => O(n)
        // space=> O(1)

        for (int i = 0; i < n; i++) {
            maxXor ^= nums[i];
        }

        if (maxXor > 0)
            return n;

        if (*max_element(nums.begin(), nums.end()) == 0) {
            return 0;
        }

        return n - 1;
    }
};
