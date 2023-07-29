class Solution {
private:
    bool dfs(int node,int color,vector<int>&col,unordered_map<int,vector<int>>&adj){
        col[node] = color;

        for(auto nbr:adj[node]){
            if(col[nbr] == -1){
                if(dfs(nbr,!color,col,adj) == false)
                return false;
            }
            //node and its nbr's color got same -> not bipartite
            else if(col[nbr] == color){
                return false;
            }
        }
        return true;
    }    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //cout<<n;
        //creating adjacency list
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>col(n,-1);
        int color = 0;
        for(int i=0;i<n;i++){
            if(col[i] == -1){
            if(dfs(i,color,col,adj) == false)
            return false;
            }
        }

        return true;
    }
};