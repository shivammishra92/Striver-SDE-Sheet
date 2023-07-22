class Solution {
public:
    // //recursive solution
    // int solve(int ind,int prevInd,vector<int>&nums){
        
    //     //base case
    //     if(ind == nums.size())
    //     return 0;

    //     //exclude
    //     int len1 = 0 + solve(ind+1,prevInd,nums);

    //     //include
    //     int len2 = 0;
    //     if(prevInd == -1 || nums[prevInd] < nums[ind])
    //      len2 = 1 + solve(ind+1,ind,nums);

    //     int maxLen = max(len1,len2);

    //     return maxLen;
    // }

    //dp solution
    int solveDP(int ind,int prevInd,vector<int>&nums,vector<vector<int>>&dp){
        
        //base case
        if(ind == nums.size())
        return 0;

        if(dp[ind][prevInd+1] != -1)
        return dp[ind][prevInd+1];

        //exclude
        int len1 = 0 + solveDP(ind+1,prevInd,nums,dp);
        
        //include
        int len2 = 0;
        if(prevInd == -1 || nums[prevInd] < nums[ind])
         len2 = 1 + solveDP(ind+1,ind,nums,dp);

        dp[ind][prevInd+1] = max(len1,len2);

        return dp[ind][prevInd+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        
        // int maxLen = solve(0,-1,nums);
        // return maxLen;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int maxLen = solveDP(0,-1,nums,dp);
        return maxLen;
    }
};