class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,set<vector<int>>&set,int index){
        if(index >= nums.size()){
            if(set.find(nums) == set.end()){
                ans.push_back(nums);
                set.insert(nums);
                return;
            }
            else
            return;
        }

        for(int i=0;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,set,index+1);
            //backtrack
            swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>set;
        int index = 0;
        solve(nums,ans,set,index);
        return ans;
    }
};