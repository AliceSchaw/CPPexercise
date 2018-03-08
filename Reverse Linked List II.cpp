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
     ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)return head;
        ListNode prehead(0);
        prehead.next=head;
        ListNode* pre=&prehead;
        for(int i=0;i<m-1;i++)pre=pre->next;        
        ListNode* pstart=pre->next;
        for(int j=m;j<n;j++)//反转链表
        {
            ListNode *p=pstart->next;//*p来遍历指针
            pstart->next=p->next;
            p->next=pre->next;
            pre->next=p;
        }
        return prehead.next;
    }
};