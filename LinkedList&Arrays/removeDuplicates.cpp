class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
       int k = st.size();
       int i=0;
       for(auto it:st){
           nums[i++] = it;
       }
       return k;
    }
};