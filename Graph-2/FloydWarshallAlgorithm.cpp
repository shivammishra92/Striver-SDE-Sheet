class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    int n = dist.size();
	   
	   //if no path is possible then changing that path's value from -1 to some max value as per our algorithm
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(dist[i][j] == -1)
	            dist[i][j] = 1e9;
	        }
	    }
	    
	    //Floyd algorithm
	    for(int helper=0;helper<n;helper++){
	        for(int src=0;src<n;src++){
	            for(int dest=0;dest<n;dest++){
	                dist[src][dest] = min(dist[src][dest],dist[src][helper]+dist[helper][dest]);
	            }
	        }
	    }
	   // to retain the matrix with -1 value where path is not possible
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(dist[i][j] == 1e9)
	            dist[i][j] = -1;
	        }
	    }

	}
};