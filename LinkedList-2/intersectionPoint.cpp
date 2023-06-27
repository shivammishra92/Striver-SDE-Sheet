/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//                    Using FLOYD'S CYCLE DETECTION ALGO
//     ListNode* detectLoop(ListNode* head){
//        ListNode* slow = head;
//        ListNode* fast = head;

//        while(fast and fast->next){
//            slow = slow->next;
//            fast = fast->next->next;
//            if(slow == fast)
//            return slow;
//        }
//        return NULL;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;
        
//         while(temp1->next != NULL){
//             temp1 = temp1->next;
//         }
//         temp1->next = temp2;
//         ListNode* intersectionPoint = detectLoop(headA);

//         if(intersectionPoint == NULL)
//         return NULL;

//         ListNode* slow = headA;

//         while(slow != intersectionPoint){
//             slow = slow->next;
//             intersectionPoint = intersectionPoint->next;
//         }
//         return slow;
//     }
// Method-2(brute force)
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
           ListNode* temp1 = headA;
           ListNode* temp2 = headB;
           int c1=0,c2=0;

           while(temp1 != NULL){
               c1++;
               temp1 = temp1->next;
           }

            while(temp2 != NULL){
               c2++;
               temp2 = temp2->next;
           }

           int k = abs(c1-c2);
           ListNode* ptrLong = NULL;
           ListNode* ptrSmall = NULL;
           if(c1>c2){
           ptrLong = headA;
           ptrSmall = headB;
           }
           else{
           ptrLong = headB;
           ptrSmall = headA;
           }

           while(k--){
               ptrLong = ptrLong->next;
           }
          
           while(ptrLong != ptrSmall){
               ptrLong = ptrLong->next;
               ptrSmall = ptrSmall->next;
           }
           return ptrSmall;       
    }
 };