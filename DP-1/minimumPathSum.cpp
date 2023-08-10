class Solution {
private:
    int solveRec(int i,int j,int m,int n,vector<vector<int>>& grid){
        //base case
        if(i == m-1 and j == n-1)
        return grid[i][j];
        if(i >= m or j >= n)
        return INT_MAX-100;//to avoid integer overflow subtract something good from INT_MAX

        int right = grid[i][j] + solveRec(i,j+1,m,n,grid);
        int down = grid[i][j] + solveRec(i+1,j,m,n,grid);

        return min(right,down);
    }
    
    int memoisation(int i,int j,int m,int n,vector<vector<int>>& grid,
    vector<vector<int>>&dp){
        //base case
        if(i == m-1 and j == n-1)
        return grid[i][j];
        if(i >= m or j >= n)
        return INT_MAX-100;//to avoid integer overflow subtract something good from INT_MAX 

        if(dp[i][j] != -1)
        return dp[i][j];

        int right = grid[i][j] + memoisation(i,j+1,m,n,grid,dp);
        int down = grid[i][j] + memoisation(i+1,j,m,n,grid,dp);

        dp[i][j] = min(right,down);
        return dp[i][j];
    }        
public:
    int minPathSum(vector<vector<int>>& grid) {
     
     int m = grid.size();
     int n = grid[0].size();
     //int minSum = solveRec(0,0,m,n,grid);
     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
     int minSum = memoisation(0,0,m,n,grid,dp);
     return minSum;   
    }
};