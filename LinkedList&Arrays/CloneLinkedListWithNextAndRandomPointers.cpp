/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head,Node* &tail,int &val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
       //1.creating a clone/copy linked list
       Node* cloneHead = NULL;
       Node* cloneTail = NULL;

       Node* temp = head;
       while(temp != NULL){
           insertAtTail(cloneHead,cloneTail,temp->val);
           temp = temp->next;
       } 

       //2.Creating a map to get random pointers
       unordered_map<Node*,Node*>oldToNew;

       Node* originalNode = head;
       Node* cloneNode = cloneHead;
       while(originalNode && cloneNode){
           oldToNew[originalNode] = cloneNode;
           originalNode = originalNode->next;
           cloneNode = cloneNode->next;
       }

       //3.Set random pointers
       originalNode = head;
       cloneNode = cloneHead;
       while(originalNode and cloneNode){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
       }

       return cloneHead;
    }
};