#include <bits/stdc++.h>
using namespace std;

class DSU{
  public:
     vector<int> parent;
     vector<int> rank;
     int n;
     
  public:
     DSU(int size){
         n = size;
         parent.resize(n);
         rank.resize(n);
         
         for(int i=0;i<n;i++){
             parent[i] = i;
             rank[i] = 0;
         }
     }
     
     int findParent(int node){
         //base case
         if(node == parent[node]){
             return node;
         }
         
         return parent[node] = findParent(parent[node]);
     }
     
     void unionByRank(int u,int v){
         u = findParent(u);
         v = findParent(v);
         
         
         if(u == v){
             return;
         }
         
         if(rank[u] < rank[v]){
             parent[u] = v;
         }
         else if(rank[v] < rank[u]){
             parent[v] = u;
         }
         else{
             rank[u]++;
             parent[v] = u;
         }
     }
     
};

class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
       
       int total_edges = edges.size();
       
       int nodes = n;
    
       unordered_set<int> st; 
       
       DSU obj(n);
       
       //path compression
       //o(E)
       for(int i=0;i<edges.size();i++){
           obj.unionByRank(edges[i][0],edges[i][1]);
       }
       
       
       //O(n)
       // find components 
       for(int i=0;i<n;i++){
           int root = obj.findParent(i);
           st.insert(root);
       }
       
       int components = st.size();
       
       if(components == 1) return 0;
       
       int extra = total_edges - (n - components);
       
       if(extra >= components-1){
           return components-1;
       }
       
       //Time compleity = O(n+E);
       //Space = O(n)
       
       return -1;
       
    }
};