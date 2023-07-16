class Solution {
  public:
    // bool chkCycleUsingDFS(int src,vector<int> adj[],unordered_map<int,bool>&visited,
    // unordered_map<int,bool>&dfsVisited){
        
    bool chkCycleUsingDFS(int src,vector<int> adj[],vector<bool>&visited,
    vector<bool>&dfsVisited){
         
        
        visited[src] = true;
        dfsVisited[src] = true;
        
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                bool aageKaAns = chkCycleUsingDFS(nbr,adj,visited,dfsVisited);
                if(aageKaAns == true)
                return true;
            }
        
            else if(dfsVisited[nbr])
            return true;
            
        }
        
        dfsVisited[src] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        
       // unordered_map<int,bool>visited;
        //unordered_map<int,bool>dfsVisited;
        
        vector<bool>visited(v,false);
        vector<bool>dfsVisited(v,false);
        bool ans = false;
        //handles all disconnected graphs
        for(int i=0;i<v;i++){
            if(!visited[i]){
                ans = chkCycleUsingDFS(i,adj,visited,dfsVisited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }

};