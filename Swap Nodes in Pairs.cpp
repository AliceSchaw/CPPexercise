//3ms
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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL) return NULL;
        ListNode **p=&head;
        ListNode *t1=head,*t2=head;
        while((t1=*p)&&(t2=t1->next)){
            t1->next=t2->next;
            t2->next=t1;
            (*p)=t2;
            p=&(t1->next);
            
        }
        return head;
        
    }
};
