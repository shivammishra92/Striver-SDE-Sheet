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
    pair<bool,int>balancedFast(TreeNode* root){

        if(root == NULL)
        {
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        pair<bool,int>left = balancedFast(root->left);
        pair<bool,int>right = balancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int>ans;
        ans.second = max(left.second,right.second) + 1;

        if(leftAns and rightAns and diff)
        ans.first = true;
        else
        ans.first = false;

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int>ans = balancedFast(root);
        return ans.first;
    }
};