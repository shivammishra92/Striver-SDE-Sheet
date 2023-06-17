class Solution
{
    public:
    //using recursion
    int solveRec(int wt[],int val[],int index,int capacity){
        
        //base case
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
                
            }
            else
            return 0;
        }
        
        int include = 0;
        if(wt[index] <= capacity){
         include = val[index] + solveRec(wt,val,index-1,capacity-wt[index]);
        }
        int exclude = 0 + solveRec(wt,val,index-1,capacity);
        
        int ans = max(include,exclude);
        
        return ans;
    }
    //using dp
    int solveMemo(int wt[],int val[],int index,int capacity,vector<vector<int>>&dp){
        
        //base case
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
                
            }
            else
            return 0;
        }
        if(dp[index][capacity] != -1)
        return dp[index][capacity];
        
        int include = 0;
        if(wt[index] <= capacity){
         include = val[index] + solveMemo(wt,val,index-1,capacity-wt[index],dp);
        }
        int exclude = 0 + solveMemo(wt,val,index-1,capacity,dp);
        
        dp[index][capacity] = max(include,exclude);
        
        return dp[index][capacity];
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int capacity, int wt[], int val[], int n) 
    { 
    //   int maxValue = solveRec(wt,val,n-1,capacity);
    //   return maxValue;
         vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
         int maxValue = solveMemo(wt,val,n-1,capacity,dp);
         return maxValue;
    
    }
};