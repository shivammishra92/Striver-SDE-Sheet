class Solution{
private:
bool isPossibleToColor(int node,int n,vector<int>color,bool graph[101][101],int col){
    for(int i=0;i<n;i++){
        //graph[i][node] == 1  means i to node there is one edge
        if(i != node && graph[i][node] == 1 && color[i] == col)
        return false;
    }
    return true;
}
private:
bool solve(int node,int m,int n,vector<int>color,bool graph[101][101]){
    if(node == n)return true;
    
    for(int col=1;col<=m;col++){
        
        if(isPossibleToColor(node,n,color,graph,col)){
            color[node] = col;
            if(solve(node+1,m,n,color,graph) == true)
            return true;
            //backtrack
            color[node] = 0;
        }
    }
    return false;
}
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n,0);
       bool ans = solve(0,m,n,color,graph);
       if(ans)return true;
       return false;
    }
};