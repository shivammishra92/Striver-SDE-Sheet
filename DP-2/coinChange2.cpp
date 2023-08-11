class Solution {
private:
    int solveRec(int index,int target,vector<int>&coins){
        //base case
        if(index == 0){
          return(target % coins[index] == 0);
        }

        int notTake = solveRec(index-1,target,coins);
        int take = 0;
        if(coins[index] <= target){
            take = solveRec(index,target-coins[index],coins);
        }

        return take + notTake;
    } 

     //   dp solution
     int memoisation(int index,int target,vector<int>&coins,vector<vector<int>>&dp){
        //base case
        if(index == 0){
          return(target % coins[index] == 0);
        }

        if(dp[index][target] != -1)
        return dp[index][target];

        int notTake = memoisation(index-1,target,coins,dp);
        int take = 0;
        if(coins[index] <= target){
            take = memoisation(index,target-coins[index],coins,dp);
        }

        dp[index][target] = take + notTake;

        return dp[index][target];
    }       
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //int ans = solveRec(n-1,amount,coins);
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = memoisation(n-1,amount,coins,dp);
        return ans;
    }
};