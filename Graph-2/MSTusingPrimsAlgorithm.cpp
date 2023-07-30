class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<bool>visited(v,false);
        //pair of wt and node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int wt = top.first;
            int node = top.second;
            
            if(visited[node])
            continue;
            
            visited[node] = true;
            sum += wt;
            
            //go for all adjacent nodes and insert into the pq if they are not visited
            for(auto nbr:adj[node]){
                //nbr -> 0th index of adj & adjNode -> 1st index of adj & edgeWt -> 2nd index of adj
                int adjNode = nbr[0];// 0th index corresponding to nbr
                int edgeWt = nbr[1];//1st index corresponding to the nbr
                if(!visited[adjNode]){
                    pq.push({edgeWt,adjNode});
                }
            }
        }
        return sum;
    }
};