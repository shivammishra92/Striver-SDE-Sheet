class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& adj, int src) {
        vector<int>dist(n,1e8);
        dist[src] = 0;
        
        //n-1 passes
        for(int i=0;i<n-1;i++){
            for(auto it:adj){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        //checking for negative cycle
        bool negativeCycleHaiKya = false;
        for(int i=0;i<n-1;i++){
            for(auto it:adj){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
                    negativeCycleHaiKya = true;
                    return {-1};
                }
            }
        }
        return dist;
    }
};