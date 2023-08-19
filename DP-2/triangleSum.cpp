class Solution {
private: 
    int solveRec(int i,int j,vector<vector<int>>&triangle){
        //base case
        if(i == triangle.size()-1)
        return triangle[triangle.size()-1][j];

        int down = triangle[i][j] + solveRec(i+1,j,triangle);
        int diagonal = triangle[i][j] + solveRec(i+1,j+1,triangle);

        return min(down,diagonal);
    } 

    int memoisation(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        //base case
        if(i == triangle.size()-1)
        return triangle[triangle.size()-1][j];

        if(dp[i][j] != -1)
        return dp[i][j];

        int down = triangle[i][j] + memoisation(i+1,j,triangle,dp);
        int diagonal = triangle[i][j] + memoisation(i+1,j+1,triangle,dp);

        dp[i][j] =  min(down,diagonal);
        return dp[i][j];
    } 

    int tabulation(int n,vector<vector<int>>&triangle){
        vector<vector<int>>dp(n,vector<int>(n,0));
        //base case will be for the last row but column can vary
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
       return dp[0][0];
    } 


public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int i=0,j=0;
        // return solveRec(i,j,triangle);
        // int n = triangle.size();
        // int m = triangle[n-1].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memoisation(0,0,triangle,dp);
        
        int n = triangle.size();
        return tabulation(n,triangle);
    }
};