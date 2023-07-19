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
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>&ans){
//         if(root == NULL)
//         return;

//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         inorder(root,ans);
//         return ans;
//     }
// };

//MORRIS TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

       vector<int>ans;
       TreeNode* curr = root;

       while(curr){

           if(curr->left == NULL){
               ans.push_back(curr->val);
               curr = curr->right;
           }

           else{

               //finding inorder predecessor
               TreeNode* pred = curr->left;
               while(pred->right != curr && pred->right){
                 pred = pred->right;
               }

               if(pred->right == NULL){
                   pred->right = curr;
                   curr = curr->left;
               }

               else{
                   pred->right = NULL;
                   ans.push_back(curr->val);
                   curr = curr->right;
               }
           }
       }
       return ans; 
    }
};