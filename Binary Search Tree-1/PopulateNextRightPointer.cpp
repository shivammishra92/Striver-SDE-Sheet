class Solution {
public:
    Node* connect(Node* root) {
       if(root == NULL)
       return NULL;

       Node* curr = root;
       while(curr->left){

           Node* temp = curr;
           while(curr){
               //step-01
               curr->left->next = curr->right;
               //step-02
               if(curr->next == NULL)
               curr->right->next = NULL;
               else
               curr->right->next = curr->next->left;
               //step-03
               curr = curr->next;
           }
           curr = temp->left;
       }
       return root;
    }
};