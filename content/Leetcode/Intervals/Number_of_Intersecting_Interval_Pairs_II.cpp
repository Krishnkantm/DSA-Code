class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }

        return a[0] < b[0];
    }

    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans = 0;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp); // nlongn

        vector<int> temp; // start //O(n)

        // o(n)
        for (int i = 0; i < n; i++) {
            temp.push_back(intervals[i][0]);
        }

        // Time =>  o(n) * (logn) => O(nlong n)
        // Complexity => O(n)
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            auto it = upper_bound(temp.begin(), temp.end(), end);

            int index = it - temp.begin();

            if (index >= temp.size()) {
                ans = ans + (n - i - 1);
            } else {
                ans = ans + (index - i - 1);
            }
        }

        return ans;
    }
};
