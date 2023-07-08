// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    // public:
    // void inorder(Node* root,vector<int>&v)
    // {
    //   if(root != NULL)
    //   {
    //       inorder(root->left,v);
    //       v.push_back(root->data);
    //       inorder(root->right,v);
    //   }
    //   else
    //   return;
       
           
    // }
    
    // int kthLargest(Node *root, int k)
    // {
    //   vector<int>v;    
    //   inorder(root,v);
    //   int ans;
    //   ans = v[v.size()-k]; 
       
    //  return ans;
    // }
    private:
    Node* solve(Node* root,int &k){
        if(root == NULL)
        return NULL;
        
        Node* rightAns = solve(root->right,k);
        if(rightAns != NULL)
        return rightAns;
        
        k--;
        if(k == 0)
        return root;
        
        Node* leftAns = solve(root->left,k);
        return leftAns;
    }
    public:
    int kthLargest(Node *root, int k)
    {
       Node* ans = solve(root,k);
       return ans->data;
    }
};