class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        deque<int>dq;//playing with indices

        // //Steps to be followed:
        // 1.Remove all smaller elements if any fall before a greater element 
        // and store elements in a decreasing fashion
        // 2.Process for remaining windows
        // 3.Remove the elements which fall out of the boundary of current window
        // 4.Again remove smaller elements if any ... same as done in step-1 
        // 5.Store the ans for current window
        // :) 

        for(int i=0;i<k;i++){
            //remove chhote elements
            while(!dq.empty() and nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //storing ans for first window
        ans.push_back(nums[dq.front()]);

        //processing remaining windows
        for(int i=k;i<nums.size();i++){
            //window ke bahar wale elements ko remove madi
            if(!dq.empty() and i-dq.front() >= k){
                dq.pop_front();
            }

            //again remove chhote elements
             while(!dq.empty() and nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //new element insert madi
            dq.push_back(i);

            //current window ka ans store kar lo
            ans.push_back(nums[dq.front()]);

         }
        return ans;
     }
};