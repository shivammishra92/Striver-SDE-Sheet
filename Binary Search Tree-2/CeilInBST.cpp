int findCeil(Node* root, int x) {
    if (root == NULL) return -1;
    vector<int>ans;
    while(root){
        
        if(root->data >= x){
            ans.push_back(root->data);
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(ans.size() == 0)return -1;
    return ans[ans.size()-1];
}