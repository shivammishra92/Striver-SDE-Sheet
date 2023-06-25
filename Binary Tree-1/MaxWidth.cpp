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
    int widthOfBinaryTree(TreeNode* root) {
       if(root == NULL)
       return 0;
       int maxWidth = 0;
       queue<pair<TreeNode*,int>>q;
       q.push({root,1}); 
       
       while(!q.empty()){
           int size = q.size();
           pair<TreeNode*,int>temp = q.front();
           int leftMost,rightMost;
           int currMin = q.front().second;
           //int parentIndex = temp.second;

           for(int i=0;i<size;i++){
              TreeNode* frontNode = q.front().first;
              int currIndex = q.front().second - currMin;
              q.pop();
              if(i == 0)
              leftMost = currIndex;
              if(i == size-1)
              rightMost = currIndex;

              if(frontNode->left){
                  q.push({frontNode->left,2LL*currIndex});
              } 
              if(frontNode->right){
                  q.push({frontNode->right,2LL*currIndex + 1});
              } 
           }
           maxWidth = max(maxWidth,rightMost-leftMost + 1);
       }
       return maxWidth;
    }
};