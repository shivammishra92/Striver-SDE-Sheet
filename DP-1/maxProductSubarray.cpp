class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     int res = nums[0];

    //     for(int i=0;i<nums.size();i++){
    //         int pro = nums[i];
    //         for(int j=i+1;j<nums.size();j++){
    //             res = max(res,pro); 
    //             pro = pro*nums[j];
    //         }
    //         res = max(res,pro);
    //     }
    //     return res;
    // }

    // moving from both the ends and calculating the prefix and sufix sum
     int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int pre = 1;
        int suff = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pre *= nums[i];
            suff *= nums[n-i-1];
            maxi = max(maxi,max(pre,suff));
            
            if(pre == 0)pre = 1;
            if(suff == 0)suff = 1;

            
        }
        return maxi;
    }
};