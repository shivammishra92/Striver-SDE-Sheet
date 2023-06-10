class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i] = i*fact[i-1];
        }
        vector<bool>visited(n+1,false);
        string ans="";
        int i=n;
        
        while(ans.length() != n){
            
            int row = k/fact[i-1];
            if(k%fact[i-1] != 0){
                row++;
            }
            
            for(int j=1;j<=n;j++){
                if(visited[j] == false)
                {
                    row--;
                }
                if(row == 0){
                    visited[j] = true;
                    ans += (j+'0');
                    break;
                }
            }
            //for next kth element to be found
            k = k%fact[i-1];
            if(k == 0)
            k = fact[i-1];
            //next (i-1)th permutations
            i--;
        }
        return ans;
    }
};