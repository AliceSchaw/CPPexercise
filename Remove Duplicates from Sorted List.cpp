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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p,*q;
        p=head;
        while(p&&p->next){
            q=p->next;
            if(q->val==p->val)
                {p->next=q->next;}
            else{p=p->next;}
        }
        return head;
    }
};