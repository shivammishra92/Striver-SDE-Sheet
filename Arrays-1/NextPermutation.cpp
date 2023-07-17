// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
           //using cpp STL function
//         next_permutation(nums.begin(),nums.end());
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int ind = -1;
         int n = nums.size();
        //finding the break point
         for(int i=n-2;i>=0;i--){
             if(nums[i] < nums[i+1]){
             ind = i;
             break;
             }
         }

         // if no break point found i.e. return the first or the smallest permutation
         if(ind == -1){
             reverse(nums.begin(),nums.end());
             return;
         }

         //swap with the next smallest element
         for(int i=n-1;i>ind;i--){
             if(nums[i]>nums[ind]){
                 swap(nums[i],nums[ind]);
                 break;
             }
         }

             //reverse or sort the left out right subsection
             reverse(nums.begin()+ind+1,nums.end());

    }
};