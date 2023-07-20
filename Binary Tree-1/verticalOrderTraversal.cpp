class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
     
        vector<vector<int>>res;
        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;

        q.push({root,{0,0}});
        //level order traversal
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if(frontNode->left)
            q.push({frontNode->left,{hd-1,lvl+1}});

            if(frontNode->right)
            q.push({frontNode->right,{hd+1,lvl+1}});

        }

        //push all the nodes into the ans vector vertical order wise
        for(auto i:nodes){
            vector<int>ans;
            for(auto j:i.second){
                //take care here
                sort(begin(j.second), end(j.second));
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
             res.push_back(ans);
        }

        return res;
    }
};