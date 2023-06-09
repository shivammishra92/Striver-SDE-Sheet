class Solution {
public:
    
    //using Recursion
    int solveRec(vector<int>&nums,int n){
        if(n == 0)
        return nums[0];
        if(n < 0)
        return 0;

        int include = solveRec(nums,n-2) + nums[n];
        int exclude = solveRec(nums,n-1) + 0;

        return max(include,exclude);
    }
    
    //using DP
    int solveUsingMemo(vector<int>&nums,int n,vector<int>&dp){
        if(n == 0)
        return nums[0];
        if(n < 0)
        return 0;

        //step-3
        if(dp[n] != -1)
        return dp[n];

        int include = solveUsingMemo(nums,n-2,dp) + nums[n];
        int exclude = solveUsingMemo(nums,n-1,dp) + 0;

        //step-2
        dp[n] = max(include,exclude);
        return dp[n];
    }

    int rob(vector<int>& nums) {
          int n = nums.size();
         //return solveRec(nums,n-1); 
         //step-1
        vector<int>dp(n+1,-1);
        return solveUsingMemo(nums,n-1,dp);
    }
};