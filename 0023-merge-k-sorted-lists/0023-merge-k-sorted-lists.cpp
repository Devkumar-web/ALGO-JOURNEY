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
//typredef pair<int,List
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>> > pq;
        for(auto it:lists){
            if(it)
            pq.push({it->val,it});
        }
        ListNode dummy=ListNode();
        ListNode *temp=&dummy;
        while(!pq.empty()){
            pair<int,ListNode*> front=pq.top();
            pq.pop();
            temp->next=front.second;
            temp=temp->next;
            if(front.second->next){
                pq.push({front.second->next->val,front.second->next});
            }   
        }
        return dummy.next;
    }
};