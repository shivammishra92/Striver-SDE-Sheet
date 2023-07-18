class Solution
{
    private:
    void dfsTopo(int src,vector<int> adj[],unordered_map<int,bool>&visited,
    stack<int>&st){
        
        visited[src] = true;
        
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                dfsTopo(nbr,adj,visited,st);
            }
        }
        //just push the element into the stack while returning back
        st.push(src);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int>ans;
	    stack<int>st;
	    unordered_map<int,bool>visited;
	    for(int i=0;i<v;i++){
	        if(!visited[i]){
	           dfsTopo(i,adj,visited,st); 
	        }
	    }
	    
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};