class Solution {
private:
    void bfs(int r,int c,vector<vector<char>>& grid,map<pair<int,int>,bool>&visited){
        queue<pair<int,int>>q;
        visited[{r,c}] = true;
        q.push({r,c});

        while(!q.empty()){
            pair<int,int>fNode = q.front();
            int x = fNode.first;
            int y = fNode.second;
            q.pop();
            
            //traversing all four possible directions
            int dx[] = {-1,0,+1,0};
            int dy[] = {0,+1,0,-1};

            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < grid.size() && newY >=0 && newY < grid[0].size() &&
                !visited[{newX,newY}] && grid[newX][newY] == '1'){
                    visited[{newX,newY}] = true;
                    q.push({newX,newY});
                } 

            }
        }

    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool>visited;
        int countIslands = 0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(!visited[{row,col}] && grid[row][col] == '1'){
                    bfs(row,col,grid,visited);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
};