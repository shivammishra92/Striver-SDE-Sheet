https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

class Solution
{
    private:
    void solve(Node* &root,int sum,vector<int>tempSum,vector<vector<int>>&ans){
        
        if(root == NULL)return;
        
        tempSum.push_back(root->key);
        
        int add = 0;
        for(int i=0;i<tempSum.size();i++){
            add += tempSum[i];
        }
        if(add == sum){
            ans.push_back(tempSum);
        }
        
        
        solve(root->left,sum,tempSum,ans);
        solve(root->right,sum,tempSum,ans);
        //backtrack
        tempSum.pop_back();
        
    }
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>>ans;
        vector<int>tempSum;
        solve(root,sum,tempSum,ans);
        return ans;
    }
};