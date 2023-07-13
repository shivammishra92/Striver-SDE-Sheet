class Solution {
public:
    // void inorder(TreeNode* root,vector<int>&ans){
    //     if(root == NULL)
    //     return;

    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);

    // }
    // bool findTarget(TreeNode* root, int k) {
    //     vector<int>ans;
    //     inorder(root,ans);
    //     int s = 0,e = ans.size()-1;

    //     while(s < e){
    //         int sum = ans[s] + ans[e];
    //         if(sum == k)
    //         return true;
            
    //         if(sum > k)
    //         e--;
    //         else
    //         s++;
    //     }
    //    return false;
    // }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& set, int k){
        if(root == NULL)return false;
        if(set.find(k - root->val) != set.end())return true;
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    }
};