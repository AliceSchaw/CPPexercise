/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//9ms
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **t1=&head;
        ListNode *t2=head;
        //error:[0],t2->next=NULL
        //for(int i=0;i<n;i++){
        for(int i=1;i<n;i++){
            t2=t2->next;
        }
        while(t2->next!=NULL){
            t2=t2->next;
            t1=&((*t1)->next);
        }
        (*t1)=(*t1)->next;
        return head;
    }
};