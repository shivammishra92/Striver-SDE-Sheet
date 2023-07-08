class Solution{
public:
    vector<int> minPartition(int amount)
    {
        //greedy algorithm
        vector<int>deno = {1,2,5,10,20,50,100,200,500,2000};
        int n = deno.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            
            while(amount >= deno[i]){
                amount -= deno[i];
                ans.push_back(deno[i]);
            }
        }
        
        return ans;
    }
};