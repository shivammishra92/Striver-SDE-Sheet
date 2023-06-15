class Solution
{
    public:
    int solveRec(string s1,string s2,int i,int j){
        //base case
        if(i == s1.length())
        return 0;
        if(j == s2.length())
        return 0;
        
        if(s1[i] == s2[j])
        return 1 + solveRec(s1,s2,i+1,j+1);
        else
        return 0 + max(solveRec(s1,s2,i+1,j),solveRec(s1,s2,i,j+1));
        
    }
    
    int solveMemo(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i == s1.length())
        return 0;
        if(j == s2.length())
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int ans = 0;
        if(s1[i] == s2[j])
        ans =  1 + solveMemo(s1,s2,i+1,j+1,dp);
        else
        ans = 0 + max(solveMemo(s1,s2,i+1,j,dp),solveMemo(s1,s2,i,j+1,dp));
        
        dp[i][j] = ans; 
        return dp[i][j];
    }
    
    int  solveTab(int x,int y,string s1,string s2){
       vector<vector<int>>dp(x+5,vector<int>(y+5,0));
        // 2D array already zero so need to initialize for base case
        // if(i == s1.length())
        // return 0;
        // if(j == s2.length())
        // return 0;
        
        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
               //copy the memo. logic
               int ans = 0;
               if(s1[i] == s2[j])
               ans =  1 + dp[i+1][j+1];
               else
               ans = 0 + max(dp[i+1][j],dp[i][j+1]);

                dp[i][j] = ans; 
            }
        }
        return dp[0][0];
       
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {   //two pointer approach
        
        //int i=0,j=0;
        // int ans = solveRec(s1,s2,i,j);
        // return ans;
        
        // vector<vector<int>>dp(x,vector<int>(y,-1));
        // return solveMemo(s1,s2,i,j,dp);
        
         
         return solveTab(x,y,s1,s2);
        
    }
};