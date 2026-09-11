class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();(

        //time => O(n) + O(10 * 10 * 9) => O(n)
        //space => O(10) => O(1)
        if (n < 3)
            return 0;

        vector<int> arr(10, 0);

        for (int i = 0; i < n; i++) {
            arr[digits[i]]++;
        }

        int ans = 0;

        for (int i = 0; i <= 9; i++) {
            if (i % 2 != 0 || arr[i] <= 0)
                continue;

            arr[i]--;

            for (int j = 0; j <= 9; j++) {

                if (arr[j] <= 0)
                    continue;
                arr[j]--;

                for (int k = 1; k <= 9; k++) {

                    if (arr[k] == 0)
                        continue;

                    ans++;
                }

                arr[j]++;
            }
            arr[i]++;
        }

        return ans;
    }
};
