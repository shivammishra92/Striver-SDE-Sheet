class Solution {
public: 
//    //recursion solution
//     int numberOfPaths(int i,int j,int m,int n){
//         //base cases
//         //invalid path
//         if(i>=m or j>=n)
//         return 0;
//         //end point reached
//         if(i==m-1 and j==n-1)
//         return 1;

//         int count = numberOfPaths(i+1,j,m,n) + numberOfPaths(i,j+1,m,n);
//         return count;

//     }
//     int uniquePaths(int m, int n) {
//         int i=0,j=0;
//         int count = numberOfPaths(i,j,m,n);
//         return count;
//     }

    // dp solution
    int numberOfPaths(int i,int j,int m,int n,vector<vector<int>>&dp){
        //base cases
        //invalid path
        if(i>=m or j>=n)
        return 0;
        //end point reached
        if(i==m-1 and j==n-1)
        return 1;

        if(dp[i][j] != -1)
        return dp[i][j];

        dp[i][j] = numberOfPaths(i+1,j,m,n,dp) + numberOfPaths(i,j+1,m,n,dp);
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        int i=0,j=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int count = numberOfPaths(i,j,m,n,dp);
        return count;
    }
};