/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// TWO POINTER APPROACH
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(n--){
            ptr2 = ptr2->next;
        }
        //EDGE CASE
        if(ptr2 == nullptr)
        return ptr1->next;

        while(ptr2->next != nullptr){
            //prev = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        //prev->next = ptr1->next;
        ptr1->next = ptr1->next->next;
        return head;
    }
};