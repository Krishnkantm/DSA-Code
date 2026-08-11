class Solution {
public:
    bool check(int k, vector<vector<int>>& mat,
               vector<vector<int>>& prefixSum) {
        int n = mat.size();
        int m = mat[0].size();

        int maxRow = -1, minRow = n;
        int maxCol = -1, minCol = m;

        for (int i = 0; i + k - 1 < n; i++) {
            for (int j = 0; j + k - 1 < m; j++) {
                int r1 = i;
                int c1 = j;

                int r2 = i + k - 1;
                int c2 = j + k - 1;

                int area = prefixSum[r2][c2];
                if (r1 - 1 >= 0)
                    area -= prefixSum[r1 - 1][c2];
                if (c1 - 1 >= 0)
                    area -= prefixSum[r2][c1 - 1];

                if (r1 - 1 >= 0 && c1 - 1 >= 0) {
                    area += prefixSum[r1 - 1][c1 - 1];
                }

                if (area != k * k) {
                    continue;
                }

                minRow = min(minRow, i);
                minCol = min(minCol, j);

                maxRow = max(maxRow, i);
                maxCol = max(maxCol, j);
            }
        }

        if (maxRow == -1)
            return false;

        if ((maxRow - minRow >= k) || (maxCol - minCol >= k)) {
            return true;
        }

        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        // o(n*m)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left_part = (i - 1 >= 0) ? prefixSum[i - 1][j] : 0;
                int upper_part = (j - 1 >= 0) ? prefixSum[i][j - 1] : 0;

                int diagonal_part =
                    (i - 1 >= 0 && j - 1 >= 0) ? prefixSum[i - 1][j - 1] : 0;

                prefixSum[i][j] =
                    (left_part + upper_part) - diagonal_part + mat[i][j];
            }
        }

        int start = 1;
        int end = min(n, m);

        int ans = 0;

        // o(log min(n,m) * O(n,m))
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (check(mid, mat, prefixSum)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // time => O(n*m) + O(log min(n,m) * O(m*n))
        // space => (n*m)

        return ans * ans;
    }
};
