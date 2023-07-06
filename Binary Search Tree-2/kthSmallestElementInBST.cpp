
class Solution {
public:
    int solve(TreeNode* &root,int &c,int &k){
        
        if(root == NULL)
        return -1;
        
        int leftAns = solve(root->left,c,k);
        if(leftAns != -1)
        return leftAns;
        
        c++;
        if(k == c)
        return root->val;
        
        
        int rightAns = solve(root->right,c,k);
        return rightAns;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        int ans = solve(root,c,k);
        return ans;
    }
};