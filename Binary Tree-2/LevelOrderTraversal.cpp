class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL)
        return {};
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
                    
            int size = q.size();
            vector<int>v;
            
            while(size--){
                TreeNode* temp = q.front();
                q.pop(); 
                
                v.push_back(temp->val);
                //cout<<temp->val;
                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            
            }
            
            ans.push_back(v);       
                       
        }

        return ans;
    }
};