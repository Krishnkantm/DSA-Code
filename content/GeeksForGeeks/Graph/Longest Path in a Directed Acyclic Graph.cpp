class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<int> distance(V,INT_MIN); //O(V)
        
        unordered_map<int,vector<vector<int>>> adj; // O(V+E)
        
       //O(E)
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
        }
        
        priority_queue<pair<int,int>> pq; // max heap //O(V)
        
        pq.push({0,src});
        distance[src] = 0;
        
        
        //O(V)
        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            //traverse nbr
            for(auto &nbr : adj[node]){
                int v = nbr[0];
                int wt = nbr[1];
                
                //maximum 
                if(distance[v] < cost + wt){
                    distance[v] = cost+wt;
                    pq.push({cost+wt,v});
                }
                
            }
        }
        
        //time => O(V+E)
        //space => O(V+E)
       
        return distance;
    }
};
