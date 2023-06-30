class Solution {
public:
    void solve(vector<int>& candidates,int target,int index,vector<int>ans,
    vector<vector<int>>&result){

    int currSum = 0;
    for(int i=0;i<ans.size();i++){
       currSum += ans[i];
    }

    if(index >= candidates.size()){
        if(target == currSum)
        result.push_back(ans);
        return;
    }

    if(target - currSum >= 0){    
    //pick the element
    int elem = candidates[index];
    ans.push_back(elem);
    solve(candidates,target,index,ans,result);
    ans.pop_back();
    }

    //dont pick the element
    solve(candidates,target,index+1,ans,result);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>>result;   
     vector<int>ans;
     int index = 0;
     solve(candidates,target,index,ans,result);
     return result;
     
    }
};