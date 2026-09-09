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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp= &dummy;
        int carry=0;
        while(l1 && l2){
            int a=l1->val;
            int b=l2->val;
            int sum=a+b+carry;
            if(sum>=10){
                sum=sum%10;
                carry=1;
            }
            else{
                carry=0;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            int sum=l1->val+carry;
            if(sum>=10){
                sum=sum%10;
                carry=1;
            }else{
                carry=0;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
            l1=l1->next;
        }

        while(l2){
            int sum=l2->val+carry;
            if(sum>=10){
                sum=sum%10;
                carry=1;
            }
            else{
                carry=0;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
            l2=l2->next;
        }

        if(carry){
            temp->next=new ListNode(carry);
        }

        return dummy.next;

    }
};