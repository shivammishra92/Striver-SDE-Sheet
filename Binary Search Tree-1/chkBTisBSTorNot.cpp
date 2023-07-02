class Solution {
public:
    
    bool solve(TreeNode* &root,long long int upperBound,long long int lowerBound){

       //agar tree null hai to vo bhi ek valid bst hai janab!!
       if(root == NULL)
       return true;

    //    //kya main jis node par khada hun,vo range me hai,check madi...
    //    if(root->val < upperBound and root->val > lowerBound){
    //    bool leftAns = solve(root->left,root->val,lowerBound);
    //    bool rightAns = solve(root->right,upperBound,root->val);
    //    return (leftAns && rightAns);
    //    }
    //    else
    //    return false;
    
     //kya main jis node par khada hun,vo range me hai,check madi...
    if((root->val < upperBound and root->val > lowerBound) and solve(root->left,root->val,lowerBound)
     and solve(root->right,upperBound,root->val)){
        return true;
    }
    else return false;

    }

    bool isValidBST(TreeNode* root) {
        long long int upperBound = 4294967296;
        long long int lowerBound = -4294967296;

        bool ans = solve(root,upperBound,lowerBound);
        return ans;
    }
};