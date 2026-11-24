class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, pair<long long, pair<int, int>>> blocks;

        // time -> O(n)
        // space -> o(n)

        int i = 1;

        while (i < n - 1) {

            int j = i;
            int element = nums[i];

            while (j < n && nums[j] == element) {
                j++;
            }

            long long curr = 1LL * j - i * 1LL;
            if (!blocks.count(element) || blocks[element].first < curr) {
                blocks[element] = {curr, {i, j - 1}};
            }

            i = j;
        }

        long long ans = LLONG_MAX;
        long long l = -1;
        long long m = -1;

        for (auto& it : blocks) {
            int element = it.first;

            pair<long long, pair<int, int>> p = it.second;

            l = p.second.first;
            m = p.second.second;

            if (l == 1 && nums[0] == element)
                l--;

            long long left = l * 1LL * element;
            long long right = (n - m - 1) * 1LL * element;

            ans = min(ans, left + right);
        }

        return ans;
    }
};
