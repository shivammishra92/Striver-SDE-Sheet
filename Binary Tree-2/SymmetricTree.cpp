/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool chkSymmetric(TreeNode* p,TreeNode* q){
        if(p == nullptr and q == nullptr)
        return true;
        if(p == nullptr or q == nullptr)
        return false;
        bool value = p->val == q->val;
        return (chkSymmetric(p->left,q->right) and chkSymmetric(p->right,q->left) and (value));
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root == nullptr)
        return true;
        
        bool chk = chkSymmetric(root->left,root->right);
        return chk;
    }
};