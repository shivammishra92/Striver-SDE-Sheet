class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
         
        unordered_map<int,int>mp;
        
        int csum = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            csum += a[i];
            
            if(csum == 0)
            ans = max(ans,i+1);
            else
            {
                if(mp.find(csum) != mp.end())
                {
                    ans = max(ans,i-mp[csum]);
                }
                else
                {
                    //inserting the current length
                    mp[csum] = i;
                }
            }
        }
        return ans;
         
    }
};