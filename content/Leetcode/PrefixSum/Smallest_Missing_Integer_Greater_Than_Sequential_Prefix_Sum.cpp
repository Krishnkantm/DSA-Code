class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<bool> temp(1276, false);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            temp[nums[i]] = true;
        }

        int sum = nums[0];
        int j = 1;

        while (j < n && nums[j] - 1 == nums[j - 1]) {
            sum += nums[j];
            j++;
        }

        while (temp[sum]) {
            sum++;
        }

        return sum;
    }
};
