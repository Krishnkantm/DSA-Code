class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();

        // time -> O(n)
        // space -> O(n)

        vector<int> ans(2, -1);

        unordered_map<int, int> mp; //(n)

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        long long product = LLONG_MIN;

        // O(n)
        for (int i = 0; i < n; i++) {
            int curr_j = target - nums[i];

            if (nums[i] > curr_j && mp.count(curr_j)) {

                if (product < (nums[i] * 1LL * curr_j)) {
                    product = (nums[i] * 1LL * curr_j);
                    ans[0] = i;
                    ans[1] = mp[curr_j];
                }
            }
        }

        return ans;
    }
};
