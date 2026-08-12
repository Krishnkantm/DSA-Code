class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        //time complexity = O(n)
        //space complexiyt => O(n)

        unordered_map<int, int> mp;

        int i = 0;

        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;

            while (i < j && mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
