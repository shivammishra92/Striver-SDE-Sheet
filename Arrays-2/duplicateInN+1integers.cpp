class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //method-01
        // while(nums[0] != nums[nums[0]]){
        //     swap(nums[0],nums[nums[0]]);
        // }
        // return nums[0];

        //method-02
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

      //method-03(Binary Search)
        int ok(vector<int>& nums,int mid){ /*function that checks how many number in given array nums is less or equal to the mid .*/
         int  count=0;
            for(auto value:nums){
               if(value<=mid){
                   count++;
             }
            }
            return count ;
      }
   int findDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(low<high){
            mid=low+(high-low)/2;
    
            if(ok(nums,mid)>mid){ /* checking duplicates if it is gretaer for passed mid that means duplicates
        is on left side so reduce search space for left subarray only */
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};