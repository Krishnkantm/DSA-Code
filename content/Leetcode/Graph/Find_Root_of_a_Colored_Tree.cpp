class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        unordered_map<int, vector<int>> adj;

        int n = colors.size();

        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        // O(n)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if ((colors[u] == 'R' && colors[v] == 'B') ||
                (colors[u] == 'B' && colors[v] == 'W') ||
                (colors[u] == 'W' && colors[v] == 'R')) {

                adj[u].push_back(v);
                outdegree[u]++;
                indegree[v]++;

            } else if ((colors[v] == 'R' && colors[u] == 'B') ||
                       (colors[v] == 'B' && colors[u] == 'W') ||
                       (colors[v] == 'W' && colors[u] == 'R')) {

                adj[v].push_back(u);
                outdegree[v]++;
                indegree[u]++;

            } else {
                return -1;
            }
        }

        int root = -1;

        // O(n)
        for (int i = 0; i < n; i++) {

            if (outdegree[i] > 2)
                return -1;

            if (indegree[i] == 0) {
                if (root != -1) {
                    return -1;
                }

                root = i;
            }
        }

        // time -> O(n)
        // space -> O(n)

        return root;
    }
};
