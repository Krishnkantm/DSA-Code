class Solution {
public:
    int solve(int x, int y, vector<int>& nums) {
        int front = 0;
        int back = 0;

        for (int i = 0; i <= x; i++) {
            front++;
        }

        for (int i = nums.size() - 1; i >= y; i--) {
            back++;
        }

        int between = 0;

        for (int i = x + 1; i < y; i++) {
            between++;
        }

        if (front < back) {

            int temp = min(between + 1, back);

            return front + temp;
        } else if (back < front) {

            int temp = min(between + 1, front);

            return back + temp;
        } else {
            if (front < between + 1) {
                return front + back;
            } else {
                return between + 1 + back;
            }
        }
    }

    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1 || n == 2) {
            return n;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int minIndex = -1;
        int maxIndex = -1;

        for (int i = 0; i < n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                minIndex = i;
            }

            if (maxi < nums[i]) {
                maxi = nums[i];
                maxIndex = i;
            }
        }

        int temp = minIndex;

        minIndex = min(minIndex, maxIndex);
        maxIndex = max(maxIndex, temp);

        cout << minIndex << endl;
        cout << maxIndex << endl;

        return solve(minIndex, maxIndex, nums);
    }
};
