//26ms
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        while(n>1){
            int k=(n+1)/2;
            //error:list[i+k] overflow
            //for(int i=0;i<k;i++){
            for(int i=0;i<n/2;i++){
                lists[i]=mergeTwoLists(lists[i],lists[i+k]);
            }
            n=k;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0);
        ListNode *p = &preHead;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
               
            }
            else{
                p->next=l2;
                l2=l2->next;
                
            }
             p = p->next;
        }
        p->next=l1?l1:l2;
        return preHead.next;
    }
};