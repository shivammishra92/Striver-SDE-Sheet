class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //manipulating data in the copy 
        vector<vector<int>>arr = grid;
       
        // queue<pair<int,int>>q;
        queue<pair<pair<int,int>,int>>q; //-> pair of {coordinates,time}

        //storing all the rotten oranges
        for(int row=0;row<arr.size();row++){
            for(int col=0;col<arr[row].size();col++){
                if(arr[row][col] == 2)
               q.push({{row,col},0});
            }
        }
        int ansTime = 0;
        while(!q.empty()){
            auto fNode = q.front();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;
            q.pop();
           

            int dx[] = {-1,0,+1,0};
            int dy[] = {0,+1,0,-1};
            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() &&
                 arr[newX][newY] == 1){
                    q.push({{newX,newY},time+1});
                    ansTime = max(ansTime,time+1);
                    //mark rotten orange
                    arr[newX][newY] = 2;
                 } 
            }
         
        }
        //if any fresh orange left
        for(int i=0;i<arr.size();i++){
           for(int j=0;j<arr[i].size();j++){
               if(arr[i][j] == 1)
               return -1;
           }
        }

       return ansTime; 
    }
};