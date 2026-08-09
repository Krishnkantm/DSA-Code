class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend()); // o(n long n)

        sort(discounts.rbegin(), discounts.rend()); // o(m long m);

        // time complexity => o(n) + o(n long n) + o(m long m)
        //  space complexity=> O(1)

        double ans = 0.0;

        int n = prices.size();
        int m = discounts.size();

        for (int i = 0; i < n; i++) {

            if (i >= m) {
                ans = ans + (double)prices[i];

            } else {
                double first = (100 - discounts[i]);
                double second = prices[i] * first;
                double third = second / 100;

                ans += third;
            }
        }

        return ans;
    }
};
