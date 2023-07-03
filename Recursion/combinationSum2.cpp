class Solution {
public:
//Memory limit exceeded 
//  void solve(vector<int>& candidates,int target,int index,vector<int>ans,
//     vector<vector<int>>&result){

//     int currSum = 0;
//     for(int i=0;i<ans.size();i++){
//        currSum += ans[i];
//     }

//     if(index >= candidates.size()){
//         if(target == currSum)
//         result.push_back(ans);
//         return;
//     }

//     if(target - currSum > 0){    
//     //pick the element
//     int elem = candidates[index];
//     ans.push_back(elem);
//     solve(candidates,target,index+1,ans,result);
//     ans.pop_back();
//     }

//     //dont pick the element
//     solve(candidates,target,index+1,ans,result);

//     }

//Efficient but here also Memory Limit Exceeded at 172th Test case
// void solve(int ind, int target,vector<int> &arr,vector<vector<int>>& result,vector<int>&ds) {
//       if (ind == arr.size()) {
//         if (target == 0) {
//           result.push_back(ds);
//         }
//         return;
//       }
//       // pick up the element 
//       if (arr[ind] <= target) {
//         ds.push_back(arr[ind]);
//         solve(ind+1, target - arr[ind], arr, result, ds);
//         ds.pop_back();
//       }

//       solve(ind + 1, target, arr, result, ds);

//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//      vector<vector<int>>result;   
//      vector<int>ans;
//      int index = 0;
//      solve(index,target,candidates,result,ans);
        
//         //using hashing through set ds
//         set<vector<int >>st;
//         //finally removing the duplicate elements
//         for(int i=0;i<result.size();i++){
//             sort(result[i].begin(),result[i].end());
//             st.insert(result[i]);
//         }
//          vector<vector<int>>finalans;
//         for(auto it =st.begin();it!=st.end();it++){
//             finalans.push_back(*it);
//         }

//      return finalans;
     
//       }
   void solve(int index,int target,vector<int>&candidates,vector<int>ds,vector<vector<int>>&res){
       if(target == 0){
           res.push_back(ds);
           return;
       }

       for(int i=index;i<candidates.size();i++){
           if(i>index && candidates[i] == candidates[i-1])
           continue;
           if(candidates[i]>target)
           break;
           ds.push_back(candidates[i]);
           solve(i+1,target-candidates[i],candidates,ds,res);
           ds.pop_back();
       }

   }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
         vector<vector<int>>res;
         vector<int>ds;
         sort(candidates.begin(),candidates.end());
         solve(0,target,candidates,ds,res);
         return res;
    }
};