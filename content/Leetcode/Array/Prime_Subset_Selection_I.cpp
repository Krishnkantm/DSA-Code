class Solution {
public:
    // O(nlog log n)
    void checkPrimes(vector<bool>& primes) {
        int m = primes.size();

        primes[0] = primes[1] = false;

        for (int i = 2; i * i < m; i++) {

            if (primes[i]) {
                for (int j = i * i; j < m; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    vector<int> maxPrimes(int n, int s) {
        if (n < 2 || s < 2) {
            return {};
        }

        vector<bool> primes(n + 1, true); // O(n)
        checkPrimes(primes);

        vector<int> validPrimes; // O(n)

        // O(n)
        for (int i = 0; i <= n; i++) {
            if (primes[i]) {
                validPrimes.push_back(i);
            }
        }

        int size = validPrimes.size();

        if (size == 0) {
            return {};
        }

        int idx1 = size - 1; // O(1)

        if (idx1 < 0) {
            return {};
        }

        vector<long long> prefix(size, 0);

        prefix[0] = validPrimes[0];

        for (int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] + validPrimes[i];
        }

        // o(log n)
        auto it2 = upper_bound(prefix.begin(), prefix.begin() + idx1 + 1, s);

        int idx2 = (it2 - prefix.begin()) - 1;

        if (idx2 < 0) {
            return {};
        }

        vector<int> ans;

        // o(n)
        for (int i = 0; i <= idx2; i++) {

            ans.push_back(validPrimes[i]);
        }

        // time -> O(n)
        // space -> O(n)

        return ans;
    }
};
