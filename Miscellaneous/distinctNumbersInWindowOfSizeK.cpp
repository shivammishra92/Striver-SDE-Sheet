https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(int i=0;i<k;i++){
        
            mp[a[i]]++;
        }
        
        ans.push_back(mp.size());
        
        for(int i=1;i<=n-k;i++){
            
            mp[a[i-1]]--;
            
            if(mp[a[i-1]] == 0)
            mp.erase(a[i-1]);
            
            mp[a[i+k-1]]++;
            ans.push_back(mp.size());
            
        }
        return ans;
        
    }
};