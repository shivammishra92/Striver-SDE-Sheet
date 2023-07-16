class Solution {
public:
    int pathSum(TreeNode* root,int& maxi){
        if(root == NULL)
        return 0;
        //taking only +ve path sum and for -ve ones considering them as 0
        int leftSum = max(0,pathSum(root->left,maxi));
        int rightSum = max(0,pathSum(root->right,maxi));
        maxi = max(maxi,leftSum+rightSum+root->val);

        return root->val + max(leftSum,rightSum);

    }

    int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;

    pathSum(root,maxi);
    return maxi;      
        
    }
};