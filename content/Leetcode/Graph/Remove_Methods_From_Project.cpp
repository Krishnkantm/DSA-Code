#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        visited[node] = true;

        for(auto &nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> adj;

        // time complexity O(E) where E is the number of edges in the graph
        // space complexity O(V+E) where V is the number of vertices in the graph
        
     
        for(int i=0;i<invocations.size();i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);

        }

        vector<bool> visited(n,false);

        dfs(k,adj,visited);

        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];

            if(!visited[u] && visited[v]){
                vector<int> ans;

                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }

        return ans;
    } 
};