class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n, 0);
        vector<int> reminder(n, 0);

        prefix[0] = 1LL * nums[0];
        reminder[0] = nums[0] % k;

        // O(n)
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + 1LL * nums[i];
            reminder[i] = nums[i] % k;
        }

        int ans = 0;
        int i = 0;
        int j = 0;

        // O(n)
        while (j < n) {
            long long sum = (i == 0) ? prefix[j] : prefix[j] - prefix[i - 1];

            if (reminder[i] == reminder[j]) {

                if (sum % k == reminder[i]) {
                    ans = max(ans, j - i + 1);
                }

                j++;

            } else {
                i = j;
            }
        }

        // time -> O(n)
        // space -> O(n) + O(n) => O(n)

        return ans;
    }
};
