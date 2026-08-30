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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        if(!headA && !headB){
            //that 
            if(headA==headB){
                return headA;
            }
            else{
                return nullptr;
            }
        }
        while(temp->next){
            temp=temp->next;
        }
        //now i got last element in temp variable
        temp->next=headB;

        //now we made acycle

        ListNode *slow=headA;
        ListNode *fast=headA;
        while(fast  && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                //that's mean we got intersection point and now 
                break;
            }
        } 

        if(!fast || !fast->next) {

             temp->next=nullptr;
             return nullptr;
        } 


        slow=headA;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }

        temp->next=nullptr;

        return slow;
    }
};