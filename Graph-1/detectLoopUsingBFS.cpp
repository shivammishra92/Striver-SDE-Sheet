class Solution {
  public:
  
    bool chkBfsCycle(int &src,unordered_map<int,bool>&visited,vector<int>adj[]){
        queue<int>q;
        unordered_map<int,int>parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr:adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                //cycle found
                else if(visited[nbr] and (nbr != parent[frontNode])){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        bool ans = false;
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                ans = chkBfsCycle(i,visited,adj);
                if(ans == true)return true;
                //break;
            }
        }
        
        // if(ans == true)
        // return true;
        // else
        // return false;
        return false;
    }
};