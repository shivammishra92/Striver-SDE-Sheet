
class Solution {
public:
    // int findPos(vector<int>& inorder,int &element,int inorderStart,int inorderEnd){

    //       for(int i=inorderStart;i<=inorderEnd;i++){
    //           if(inorder[i] == element)
    //           return i;
    //       }

    //       return -1;
    // }
    void findPos(vector<int>& inorder,unordered_map<int,int>&mp,int inorderStart,int inorderEnd){
        for(int i=inorderStart;i<=inorderEnd;i++){
            mp[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder,vector<int>& preorder,int &index,int inorderStart,int inorderEnd,int n,unordered_map<int,int>&mp){
           
           if(index >= n || inorderStart > inorderEnd){
               return NULL;
           }

           int element = preorder[index++];
           TreeNode* root = new TreeNode(element);
           //int position = findPos(inorder,element,inorderStart,inorderEnd);
           int position = mp[element];
           root->left = solve(inorder,preorder,index,inorderStart,position-1,n,mp);
           root->right = solve(inorder,preorder,index,position+1,inorderEnd,n,mp);

           return root;
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int inorderStart = 0,inorderEnd = preorder.size()-1;
       int n = preorder.size();
       int index = 0;
       unordered_map<int,int>mp;
       findPos(inorder,mp,0,n-1);
       TreeNode* ans = solve(inorder,preorder,index,inorderStart,inorderEnd,n,mp); 
       return ans; 
    }
};