class Solution {
public:
 void findPos(vector<int>& inorder,unordered_map<int,int>&mp,int inorderStart,int inorderEnd){
        for(int i=inorderStart;i<=inorderEnd;i++){
            mp[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int &index,int inorderStart,int inorderEnd,unordered_map<int,int>&mp){
           
           if(index < 0 || inorderStart > inorderEnd){
               return NULL;
           }

           int element = postorder[index--];
           TreeNode* root = new TreeNode(element);
           //int position = findPos(inorder,element,inorderStart,inorderEnd);
           int position = mp[element];
           //LRN
           root->right = solve(inorder,postorder,index,position+1,inorderEnd,mp);
           root->left = solve(inorder,postorder,index,inorderStart,position-1,mp);
           
           return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int inorderStart = 0,inorderEnd = postorder.size()-1;
       int index = postorder.size()-1;
       
       unordered_map<int,int>mp;
       findPos(inorder,mp,0,inorderEnd);
       TreeNode* ans = solve(inorder,postorder,index,inorderStart,inorderEnd,mp); 
       return ans; 
    }
};