class Solution {
public:
    void checkPrimes(vector<bool>& primes) {

        int n = primes.size();

        primes[0] = primes[1] = false;

        for (int i = 2; i * i < n; i++) {

            if (primes[i]) {

                for (int j = i * i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    vector<int> maxPrimeSubset(int n, int s) {
        // base case
        if (n < 2 || s < 2) {
            return {};
        }

        vector<bool> primes(n + 1, true);
        checkPrimes(primes); // O(n log log n)

        vector<int> validPrimes;

        // o(n)
        for (int i = 0; i <= n; i++) {
            if (primes[i]) {
                validPrimes.push_back(i);
            }
        }

        int size = validPrimes.size();

        if (size == 0)
            return {};

        vector<int> dp(s + 1, INT_MAX);
        dp[0] = 0;

        vector<vector<bool>> trackOfPrimes(n + 1, vector<bool>(s + 1, false));

        for (int i = size - 1; i >= 0; i--) {
            int p = validPrimes[i];

            for (int sum = s; sum - p >= 0; sum--) {

                if (dp[sum - p] == INT_MAX)
                    continue;

                int include = dp[sum - p] + 1;

                // include < dp[sum] // fewest prime
                if (include <= dp[sum]) {
                    dp[sum] = include;
                    trackOfPrimes[i][sum] = true;
                }
            }
        }

        int maxSum = 0;

        for (int i = s; i >= 0; i--) {
            if (dp[i] != INT_MAX) {
                maxSum = i;
                break;
            }
        }

        vector<int> ans;

        for (int i = 0; i < size && maxSum >= 0; i++) {
            int p = validPrimes[i];

            if (trackOfPrimes[i][maxSum]) {
                ans.push_back(p);
                maxSum -= p;
            }
        }

        // O(n log log n) + O(n) + O(m * O(s)) + O(s) + O(m) -> O(m*O(s))
        // space o(n) + O(m) + O(s) + O(n*s) => O(n*s)

        return ans;
    }
};
