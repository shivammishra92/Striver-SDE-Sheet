void solveLeftView(Node*root,vector<int>&ans,int lvl)
{
    if(root == NULL)
    return;
    
    if(ans.size() == lvl)
    ans.push_back(root->data);
    
    solveLeftView(root->left,ans,lvl+1);
    solveLeftView(root->right,ans,lvl+1);
    
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   solveLeftView(root,ans,0);
   return ans;
}