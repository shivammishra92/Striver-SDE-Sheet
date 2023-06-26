class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     int sum = 0;
     if(root == NULL or (root->left == NULL and root->right == NULL))
     return true;
     else
     {
         if(root->left != NULL)
         sum += root->left->data;
         
         if(root->right != NULL)
         sum += root->right->data;
     }
     
     if(sum == root->data and isSumProperty(root->left) and isSumProperty(root->right))
     return true;
     else
     return false;
     
    }
};