/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private: stack<TreeNode*>st;    
public:
    
    BSTIterator(TreeNode* root) {
        //push all the left nodes
        pushAll(root);
    }
    
    int next() {
        //get the middle node i.e. N of inorder
        TreeNode* temp = st.top();
        st.pop();
        //go to right i.e. R of inorder
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(!st.empty())return true;
        return false;
    }

    void pushAll(TreeNode* root){
        if(root == NULL)return;
        if(root!=NULL){
        st.push(root);
        pushAll(root->left);
        }

        // for(;root!=NULL;root=root->left)
        // st.push(root);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */