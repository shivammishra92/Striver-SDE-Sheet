// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//       vector<vector<int>>res;
//       unordered_map<int,int>mp;
//       for(int i=0;i<nums.size()-1;i++){
//           int targetSum = nums[i];
//           //unordered_map<int,int>mp;
//           mp[nums[i]]--;
//           vector<int>ans;
//           for(int j=i+1;j<nums.size()-1;j++){
//              mp[nums[j]]--;
//              int moreNeeded = -(targetSum + nums[j]);
//              if(mp.find(moreNeeded) != mp.end()){
//                 ans.push_back(nums[i]);
//                 ans.push_back(nums[j]);
//                 ans.push_back(moreNeeded);
//                 break;
//              }
//              mp[nums[j]]++;
//           }
//           mp[nums[i]]++;
//           if(ans.size())
//           res.push_back(ans);
//       }
//        // using hashing through set ds
//         set<vector<int >>st;
//         //finally removing the duplicate elements
//         for(int i=0;i<res.size();i++){
//             sort(res[i].begin(),res[i].end());
//             st.insert(res[i]);
//         }
//          vector<vector<int>>finalans;
//         for(auto it =st.begin();it!=st.end();it++){
//             finalans.push_back(*it);
//         }  
//        return finalans; 
//     }
// };

class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>>res;
     sort(nums.begin(),nums.end());

     for(int i=0;i<nums.size()-2;i++){
       
        if(i == 0 || (i>0 && nums[i] != nums[i-1])){
           int l = i+1;
           int h = nums.size()-1;
           int sum = 0 - nums[i];
           while(l<h){
               
              if(nums[l] + nums[h] == sum){
                 vector<int>ans;
                 ans.push_back(nums[i]);
                 ans.push_back(nums[l]);
                 ans.push_back(nums[h]);
                 res.push_back(ans);

                 while(l<h and nums[l] == nums[l+1])l++;
                 while(l<h and nums[h] == nums[h-1])h--;

                 l++;
                 h--;
              }
              else if(nums[l] + nums[h] < sum)
              l++;
              else
              h--;
           }
        }
     }
     return res;
   }
};