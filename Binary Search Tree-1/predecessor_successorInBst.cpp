/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void solve(Node* root,int key,Node*& pre,Node*& suc){
    if(root == NULL)
        return;
        
    if(root->key == key){
        solve(root->left,key,pre,suc);
        solve(root->right,key,pre,suc);
    }
    else if(root->key > key){
        suc = root;
        solve(root->left,key,pre,suc);
    }
    else
    {
        pre = root;
        solve(root->right,key,pre,suc);
    }
    
    
}
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
       solve(root,key,pre,suc);   
    }
};