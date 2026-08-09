class Solution {
public:
    pair<long long,long long> bfs(unordered_map<long long,vector<long long>>& adj,bool flag,long long original_height,vector<int>& nums) {
       
        queue<pair<long long, long long>> q; //{node,height}
          // {node,depth}

        long long height = 0;
        long long ans = 0;

        q.push({0, 1});
        
        while (!q.empty()) {
            long long node = q.front().first;
            long long d = q.front().second;
            q.pop();

            height = max(height, d);

            if(flag){
                 ans = ans + (nums[node] * 1LL) * 1LL * (original_height - d + 1);
            }

            for (auto& nbr : adj[node]) {
                q.push({nbr, d + 1});
            }
        }

        return {height,ans};
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<long long, vector<long long>> adj;
       
       //o(n)
        for (int i = 1; i < parent.size(); i++) {
            adj[parent[i] * 1LL].push_back(i * 1LL);
        }

        long long height = bfs(adj, false, 0, nums).first; //(n) {height,ans};

        long long result = bfs(adj, true, height, nums).second; // O(n)

        // time complexit  => O(n) + o(n) + o(n) => O(n);
        //space complexity => O(n) + o(n) + o(n) => O(n)
 
        return result;
    }
};
