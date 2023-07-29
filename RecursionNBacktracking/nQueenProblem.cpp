class Solution{
public:
   
    unordered_map<int,bool>leftChk;
    unordered_map<int,bool>upperLeftChk;
    unordered_map<int,bool>bottomLeftChk;
    
    void printSol(vector<vector<int>>&board,int n,vector<vector<int>>&ans){
        vector<int>output;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(board[j][i] == 1)
                output.push_back(j+1);
            }
        }
        
        ans.push_back(output);
        
        
    }
    
    bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        
        if(leftChk[row] == true)
        return false;
        
        if(upperLeftChk[(n-1)+col-row] == true)
        return false;
        
        if(bottomLeftChk[row+col] == true)
        return false;
        
        
        return true;
    }

    void solve(vector<vector<int>>&board,int col,int n,vector<vector<int>>&ans){
        
        //base case
        if(col >= n)
        {
            printSol(board,n,ans);
            return;
        }
        
        for(int row=0;row<n;row++){
             
             //check for safety
             if(isSafe(row,col,board,n)){
                 
                 //rakh do
                 board[row][col] = 1;

                 //mapping...
                 leftChk[row] = true;
                 bottomLeftChk[row+col] = true;
                 upperLeftChk[(n-1)+col-row] = true;
                 
                 //aab aage rec bhaiya sambhal lenge...
                 solve(board,col+1,n,ans);
                 
                 //backtrack karnaa maat bhul jana bhaiiiii...jaaan...
                 board[row][col] = 0;
                 leftChk[row] = false;
                 bottomLeftChk[row+col] = false;
                 upperLeftChk[(n-1)+col-row] = false;
             }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        
        int col = 0;
        solve(board,col,n,ans);
        
        
        return ans;
        
        
    }
};
