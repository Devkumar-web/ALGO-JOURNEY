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
class Solution {
public:
    ListNode* reverse(ListNode* head){
        //lets know that 
        ListNode * prev=nullptr;
        ListNode* curr=head;
        ListNode* next=curr->next;
        if(!next){
            return curr;
        }
        while(next){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //now we have to find last node of first half
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next==nullptr){
            //that's mean 
            return true;
        }
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow->next represent next part starting node
        ListNode* first=head;
        ListNode* second=reverse(slow->next);

        

        //now we should start our iteration over second node
        while(second){
            if(first->val != second->val){
                reverse(slow->next);
                return false;
            }
            first=first->next;
            second=second->next;
        }

        return true;

    }
};