class Solution {
public:
    long long dfs(int node, vector<int>& op, vector<int>& score,
                  unordered_map<int, vector<int>>& adj) {

        long long sum = score[node];
        long long min_value = LLONG_MAX;

        // nbr traverse
        for (auto& nbr : adj[node]) {

            long long value = dfs(nbr, op, score, adj);

            sum += value;
            min_value = min(min_value, value);
        }

        // leaf node
        if (adj[node].empty()) {
            return score[node];
        }

        if (op[node] == 1) {
            sum -= min_value;
        } else {
            sum -= min(0LL, min_value);
        }

        return sum;
    }

    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        unordered_map<int, vector<int>> adj;

        // o(n)
        for (int i = 1; i < parent.size(); i++) {
            int u = parent[i];
            int v = i;

            adj[u].push_back(v);
        }

        // time -> O(n)
        // space -> O(n)

        return dfs(0, op, score, adj);
    }
};
