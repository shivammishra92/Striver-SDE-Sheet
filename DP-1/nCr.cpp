class Solution{
public:
    int nCr(int n, int r){
        if(r > n)return 0;
        if(r == n or r == 1)
        return 1;
        
        int dp[r+1] = {0};
        dp[0] = 1;
        int mod = 1e9 + 7;
        
        for(int i=1;i<=n;i++){
            for(int j = min(i,r);j>0;j--){
                dp[j] = dp[j]%mod + dp[j-1]%mod;
            }
        }
        return dp[r] % mod;
    }
};