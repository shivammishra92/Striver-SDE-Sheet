class Solution {
public:
    // using recursion
    int solveRec(vector<int>& coins,int amount){
        if(amount == 0)
        return 0;
        if(amount < 0)
        return INT_MAX;

        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveRec(coins,amount-coins[i]);
            //INT_MAX agar ans aya to usme kuch nahi karna
            if(ans != INT_MAX)
            mini = min(mini,ans+1);
        }
        return mini;
    }

    //dp top-down approach
    int solveMemo(vector<int>& coins,int amount,vector<int>& dp){
        if(amount == 0)
        return 0; 
        if(amount < 0)
        return INT_MAX;
        
        //ans already exists
        if(dp[amount] != -1)
        return dp[amount];
       
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveMemo(coins,amount-coins[i],dp);
            //INT_MAX agar ans aya to usme kuch nahi karna
            if(ans != INT_MAX)
            mini = min(mini,ans+1);
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveRec(coins,amount);
        // if(ans == INT_MAX)
        // return -1;
        // else
        // return ans;
        vector<int>dp(amount+1,-1);
        int ans = solveMemo(coins,amount,dp);
        if(ans == INT_MAX)
        return -1;
        else
        return ans;
    }
};