class Solution {
  public:
    int maxDia(Node* root,int& maxi){
        if(root == NULL)
        return 0;
        
        int lh = maxDia(root->left,maxi);
        int rh = maxDia(root->right,maxi);
        maxi = max(maxi,lh+rh+1);
        
        return 1 + max(lh,rh);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int maxi = 0;
        int height = maxDia(root,maxi);
        //we are only concerned with maxi i.e. max dia
        return maxi;
    }
    
}; 