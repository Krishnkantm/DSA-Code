class Solution {
public:
    // o(1)
    int distance(int pointer, int digit) {
        return min((digit - pointer + 10) % 10, (pointer - digit + 10) % 10);
    }

    int minRotations(int n, string s) {
        int original_cost = 0;

        int pointer = 0;

        // O(n)
        for (int i = 0; i < n; i++) {
            original_cost += distance(pointer, s[i] - '0');
            pointer = s[i] - '0';
        }

        // k == 0;

        int ans = original_cost;
        int cost_For_k_zero = 0;

        pointer = 0;

        // O(n)
        for (int i = n - 1; i >= 0; i--) {
            cost_For_k_zero += distance(pointer, s[i] - '0');
            pointer = s[i] - '0';
        }

        // k > 0 //O(n)
        for (int k = 1; k < n; k++) {
            int old_cost = distance(s[k - 1] - '0', s[k] - '0');
            int new_cost = distance(s[k - 1] - '0', s[n - 1] - '0');

            int updates = original_cost - old_cost + new_cost;

            ans = min(ans, updates);
        }

        // time -> O(n)
        // space -> O(1);

        return min(ans, cost_For_k_zero);
    }
};
