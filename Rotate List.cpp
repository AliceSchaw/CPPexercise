/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//若k>n,则不旋转
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p,*q;
        q=head;
        p=q;
        if(p){
            for(int i=0;i<k;i++){
                p=p->next;
                if(p==NULL) return head;
            }

            while(p->next){
                q=q->next;
                p=p->next;
            }

            p->next=head;
            head=q->next;
            q->next=NULL;  

        }
        return head;
    }
};
//若k>n,取k=k%n
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
            if(!head || k==0) return head;
            ListNode* p1 = head, *p2 = head;
            for(int i=0;i<k;i++){ // move the faster pointer for k steps first
                if(p1->next) p1 = p1->next;
                else{
                    k = k%(i+1);//if k is greater than the length of the list, make k = k%length
                    i = -1; // and count from the beginning again
                    p1 = head; // move p1 to head and count again
                }
            }
            while(p1->next!=NULL){
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = head;
            head = p2->next;
            p2->next = NULL;
            return head;
     }
};