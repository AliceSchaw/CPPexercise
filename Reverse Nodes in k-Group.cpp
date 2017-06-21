//29ms
/*
 0 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |    | 
pre  cur  nex  tmp

 0 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |    | 
pre       cur  nex  tmp

 0 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    | 
pre            cur  nex  tmp
*/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(0);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k){
            cur=pre->next;
            nex=cur->next;
            //
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
                
            }
            pre=cur;
            num-=k;
        }
        return preheader->next;
    }
};