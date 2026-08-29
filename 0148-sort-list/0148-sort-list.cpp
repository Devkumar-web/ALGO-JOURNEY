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
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    
    ListNode* merge(ListNode* first,ListNode* second){
        ListNode* head;
    ListNode* temp;
    if(first->val > second->val){
        temp=second;
        second=second->next;
    }
    else{
        temp=first;
        first=first->next;
    }

    head=temp;
        //now we have to merge two sorted list
        while(first && second){
            if(first->val > second->val){
               head->next=second;
               head=head->next;
               second=second->next;
            }
            else{
                head->next=first;
               head=head->next;
               first=first->next;
            }
        }


        while(first){
            head->next=first;
            head=head->next;
            first=first->next;
        }

        while(second){
            head->next=second;
            head=head->next;
            second=second->next;
        }



        return temp;
    }
    ListNode* mergesort(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        //now we got have to find mid for that
        ListNode* mid=middle(head);
        ListNode* temp=mid->next;
        mid->next=nullptr;

        ListNode * first=mergesort(head);
        ListNode * second=mergesort(temp);
        
        return merge(first,second);

    }
    ListNode* sortList(ListNode* head) {
        if(!head){
            return head;
        }

        //tommorrow we just have to start
        
        //so we have to apply merge sort

        return mergesort(head);
        
        

        
    }
};