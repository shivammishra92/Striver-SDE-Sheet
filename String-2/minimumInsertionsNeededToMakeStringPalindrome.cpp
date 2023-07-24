class Solution {
public:
//lcs logic
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
  
    int longestPalinSubseq(string& A) {
        string first = A;
        reverse(A.begin(),A.end());
        string second = A;
        int x = first.length();
        int y = x;
        int i = 0,j = 0;
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return solveMemo(first,second,i,j,dp);
    }

    int minInsertions(string s) {
        return s.size() - longestPalinSubseq(s);
    }
};