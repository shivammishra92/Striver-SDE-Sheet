class Solution {
private: 
    //int mod = (int)(1e9 + 7);   
        // dp solution
    int numberOfPaths(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid,           
        vector<vector<int>>&dp){
        //base cases
        //obstacle found
        if(i < m and j < n and obstacleGrid[i][j] == 1)
        return 0;
        //invalid path
        if(i>=m or j>=n)
        return 0;
        //end point reached
        if(i==m-1 and j==n-1)
        return 1;

        if(dp[i][j] != -1)
        return dp[i][j];

        dp[i][j] = numberOfPaths(i+1,j,m,n,obstacleGrid,dp) + numberOfPaths(i,j+1,m,n, 
        obstacleGrid,dp);
        return dp[i][j] ;

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i=0,j=0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int count = numberOfPaths(i,j,m,n,obstacleGrid,dp);
        return count;
    }
};