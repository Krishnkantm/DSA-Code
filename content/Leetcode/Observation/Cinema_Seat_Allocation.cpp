class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end()); // O(mlongm)

        int ans = 0;
        int m = reservedSeats.size();

        int i = 0;
        // seat reserved

        int used_row = 0;

        // o(m)
        while (i < m) {
            int row = reservedSeats[i][0];
            vector<int> curr(11, 0);
            used_row++;

            while (i < m && row == reservedSeats[i][0]) {
                int seat = reservedSeats[i][1];
                curr[seat] = 1;
                i++;
            }

            // prefixSum
            // O(10)
            for (int j = 1; j <= 10; j++) {
                curr[j] = curr[j] + curr[j - 1];
            }

            bool a = false;

            if (curr[5] - curr[1] == 0) {
                a = true;
                ans++;
            }

            if (a) {
                if ((curr[9] - curr[5]) == 0) {
                    ans++;
                }
            } else {
                if ((curr[7] - curr[3]) == 0) {
                    ans++;
                } else if ((curr[9] - curr[5]) == 0) {
                    ans++;
                }
            }
        }

        // time => (m long m + (O(m)*10)) =>m log m
        // space => O(11)

        int remaining_row = n - used_row;
        ans = ans + (remaining_row * 2);
        return ans;
    }
};
