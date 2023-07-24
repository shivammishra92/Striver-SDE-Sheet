class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        vector<int>dist(v,INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            
            auto topElement = *st.begin();
            int nodeDistance = topElement.first;
            int node = topElement.second;
            //pop from set
            st.erase(st.begin());
            
            //Here nbr[0]->nbr.first
            //nbr[1]->nbr.second

            for(auto nbr : adj[node]){
                
                if(nodeDistance + nbr[1] < dist[nbr[0]]){
                    //then fetch that node to update it
                    auto oldNode = st.find({dist[nbr[0]],nbr[0]});
                    //found then erase it
                    if(oldNode != st.end())
                    st.erase(oldNode);
                    //insert/update with new distance both in dist array and set
                    dist[nbr[0]] = nodeDistance + nbr[1];
                    st.insert({dist[nbr[0]],nbr[0]});
                    
                }
            }
        }
       return dist; 
    }
};