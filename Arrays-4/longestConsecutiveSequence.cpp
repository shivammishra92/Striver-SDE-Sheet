class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        
        if(nums.size() == 0)
        return 0;

        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        
        int maxLen = 1;
        for(auto it:set){
            if(set.find(it-1) == set.end()){
              int n = it;
              int c = 1;
                  while(set.find(n+1) != set.end()){
                      c++;
                      n += 1;
                  }
                 maxLen = max(maxLen,c);
            }
        }
        return maxLen;
    }
};