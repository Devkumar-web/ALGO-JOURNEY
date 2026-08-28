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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next==nullptr){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* s1=odd;
        ListNode* s2=even;
        while(s2 && s2->next){
            s1->next=s1->next->next;
            s1=s1->next;
                 s2->next=s2->next->next;
                  s2=s2->next;
        }
        s1->next=even;

        return odd;
    }
};