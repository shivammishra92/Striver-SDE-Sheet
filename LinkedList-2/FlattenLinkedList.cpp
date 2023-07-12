

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    Node* merge(Node* &down,Node* &right)
    {
        if(down==NULL)
        {
            return right;
        }
        if(right==NULL)
        return down;
      
      Node* ans=new Node(-1);
      Node* temp=ans;
      
      while(down!=NULL&&right!=NULL)
      {
          if(down->data<right->data)
          {
              temp->bottom=down;
              temp=temp->bottom;
              down=down->bottom;
               
          }
          else
          {
              temp->bottom=right;
               temp=temp->bottom;
              right=right->bottom;
               
          }
      }
       
    if(down!=NULL) 
    temp->bottom = down; 
    else 
    temp->bottom = right; 
      
      ans=ans->bottom;
      return ans;
        
  
  
    }
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL||root->next==NULL)
   return root;
   Node* down=root;   
 
   
  Node* right=root->next;
   
  right = flatten(right); 
 
        // now merge 
        Node* res = merge(down, right); 
  
        return res; 
  
}