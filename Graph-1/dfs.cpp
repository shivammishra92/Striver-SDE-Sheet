class Solution {
  public:
    void solve(int src,vector<int> adj[],unordered_map<int,bool>&visited,
    vector<int>&ans){
        ans.push_back(src);
        visited[src] = true;
        
        for(auto neighbour:adj[src]){
            if(!visited[neighbour]){
                solve(neighbour,adj,visited,ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        vector<int>ans;
        int src = 0;
        solve(src,adj,visited,ans);
        return ans;
    }
};