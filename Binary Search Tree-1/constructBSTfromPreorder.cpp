class Solution {
public:
TreeNode* build(vector<int>&pre,int &i,int ub)
    {
        if(i == pre.size() or pre[i] > ub)
        return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        
        root->left = build(pre,i,root->val);
        root->right = build(pre,i,ub);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i=0;
       TreeNode* root =  build(preorder,i,INT_MAX);

       return root;

    }
};