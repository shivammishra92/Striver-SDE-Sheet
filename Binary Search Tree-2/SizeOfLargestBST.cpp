/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeData{
public:    
  int size;
  int maxVal;
  int minVal;
  bool validBst;
  
  NodeData() {
		
	}
  
  NodeData(int maxSize,int maxVal,int minVal,bool validBst){
  this->size = maxSize;
  this->maxVal = maxVal;
  this->minVal = minVal;
  this->validBst = validBst;
  }
  
};

class Solution{
    private:
    NodeData* findLargestBST(Node* root,int &ans){
        if(root == NULL){
            NodeData* temp = new NodeData(0,INT_MIN,INT_MAX,true);
            return temp;
        }
        
        //move left and right
        NodeData* leftKaAns = findLargestBST(root->left,ans);
        NodeData* rightKaAns = findLargestBST(root->right,ans);
        
        //now actual processing/game starts
        NodeData* currNode = new NodeData();
        currNode->size = leftKaAns->size + rightKaAns->size + 1;
        currNode->maxVal = max(root->data,rightKaAns->maxVal);
        currNode->minVal = min(root->data,leftKaAns->minVal);
        
        if(leftKaAns->validBst && rightKaAns->validBst && root->data > leftKaAns->maxVal
        && root->data < rightKaAns->minVal){
            currNode->validBst = true;
        }
        else{
            currNode->validBst = false;
        }
        
        if(currNode->validBst == true)
        ans = max(ans,currNode->size);
        
        return currNode;
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int largestSize = 0;
        findLargestBST(root,largestSize);
        return largestSize;
    }
};