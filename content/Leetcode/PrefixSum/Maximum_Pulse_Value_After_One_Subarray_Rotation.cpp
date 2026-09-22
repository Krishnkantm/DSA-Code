class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0); // O(n)

        // step1

        // O(n)
        for (int i = 0; i < n; i++) {
            int value = nums[i];

            if (i % 2 != 0) {
                value *= -1;
            }

            prefix[i + 1] = prefix[i] + 1LL * value;
        }

        long long ans = prefix[n];

        // step2
        long long maxForL[2] = {LLONG_MIN, LLONG_MIN};  // O(2)
        long long maxForL1[2] = {LLONG_MIN, LLONG_MIN}; // O(2)

        // step 3

        // O(n)
        for (int r = 1; r < n; r++) {
            int l = r - 1;

            maxForL[l % 2] =
                max(maxForL[l % 2], prefix[l]); // different parity  l..r

            // edge
            if (l >= 1) {
                maxForL1[l % 2] =
                    max(maxForL1[l % 2], prefix[l]); // same parity l+1 .. r
            }

            int opposite = 1 - (r % 2);

            // case 1 different parity
            if (maxForL[opposite] != LLONG_MIN) {
                long long new_gain = 2 * (maxForL[opposite] - prefix[r + 1]);
                ans = max(ans, prefix[n] + new_gain);
            }

            // case 2 same parity
            if (maxForL1[opposite] != LLONG_MIN) {
                long long new_gain = 2 * (maxForL1[opposite] - prefix[r + 1]);
                ans = max(ans, prefix[n] + new_gain);
            }
        }

        // time -> O(n)
        // space -> O(n) + O(2) + O(2) => O(n)

        return ans;
    }
};
