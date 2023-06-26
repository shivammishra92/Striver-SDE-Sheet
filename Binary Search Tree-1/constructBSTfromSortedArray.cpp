class Solution {
public:
    TreeNode* solve(vector<int>&nums,TreeNode* root,int s,int e){
       if(s > e)
       return NULL;

       int mid = (s+e)/2;
       root = new TreeNode(nums[mid]);
       root->left = solve(nums,root->left,s,mid-1);
       root->right = solve(nums,root->right,mid+1,e);

       return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int s = 0;
       int e = nums.size()-1;
       //int mid;      
       //int mid = (s+e)/2;
       TreeNode* root;
       root = solve(nums,root,s,e);
       return root;

    }
};