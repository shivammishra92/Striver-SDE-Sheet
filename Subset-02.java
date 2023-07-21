class Solution {
public:
    // BRUTE FORCE
    void solve(int index,vector<int>&nums,vector<int>ans,set<vector<int>>&st){

        if(index >= nums.size()){
            sort(ans.begin(),ans.end());
            st.insert(ans);
            return;
        }

        //exclude
        solve(index+1,nums,ans,st);

        //include
        ans.push_back(nums[index]);
        solve(index+1,nums,ans,st);
        ans.pop_back();

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

      vector<vector<int>>result;
      set<vector<int>>st;
      vector<int>ans;
      int index = 0;
      solve(index,nums,ans,st); 

      for(auto it=st.begin();it!=st.end();it++){
          result.push_back(*it);
      } 
      return result;
    }
};



//Optimal Code(Java)
class Solution {
    public void solve(int index,int[]nums,List<Integer>ds,List<List<Integer>>ansList){
        ansList.add(new ArrayList<>(ds));

        for(int i=index;i<nums.length;i++){

            if(i != index && nums[i] == nums[i-1])
            continue;

            ds.add(nums[i]);
            solve(i+1,nums,ds,ansList);
            ds.remove(ds.size()-1);
        }

    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>>ansList = new ArrayList<>();
        List<Integer>ds = new ArrayList<>();
        Arrays.sort(nums);
        solve(0,nums,ds,ansList);
        return ansList;
    }
}