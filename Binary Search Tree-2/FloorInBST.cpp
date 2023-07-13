void solve(Node* root,int x,vector<int>&ans){
     
     if(root == NULL)
     return;
     
     if(root->data == x){
     ans.push_back(root->data);
     return;
     }
     
     else if(root->data <= x){
     ans.push_back(root->data);
     solve(root->right,x,ans);
     
     }
     
     else
     return solve(root->left,x,ans);
}

int floor(Node* root, int x) {
    
    vector<int>ans;
    solve(root,x,ans);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    if(ans.size() == 0)
    return -1;
    int res = ans[ans.size()-1];
    
    return res;
}