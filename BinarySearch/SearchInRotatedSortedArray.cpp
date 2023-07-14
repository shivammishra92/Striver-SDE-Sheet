class Solution {
public:
    int getPivot(vector<int>&nums){
        int s = 0,e = nums.size()-1;
        int mid = s+(e-s)/2;
      while(s<=e){
        //edge case->single element
        if(s == e)
        return s;

        if(mid <=e and nums[mid] > nums[mid+1])
        return mid;

        if(mid-1 >= s and nums[mid] < nums[mid-1])
        return mid-1;

        //handle if-else here carefully  
        if(nums[mid] < nums[s])
        e = mid-1;
        else
        s = mid+1;

        mid = s+(e-s)/2;
      }
      return -1;
    }

    int bs(vector<int>&nums,int s,int e,int target){
        int mid = s+(e-s)/2;

        while(s<=e){
            if(nums[mid] == target)
            return mid;
            else if(nums[mid]>target)
            e = mid-1;
            else
            s = mid+1;

            mid = s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0,e = nums.size()-1;
        int pivotIndex = getPivot(nums);
        int ans = 0;
        if(target >= nums[0] and target <= nums[pivotIndex])
        return bs(nums,0,pivotIndex,target);
        else
        return bs(nums,pivotIndex+1,e,target);
    }
};