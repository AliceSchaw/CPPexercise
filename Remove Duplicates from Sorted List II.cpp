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
        if (!head) return 0;
        if (!head->next) return head;
        
        int val = head->val;
        ListNode* p = head->next;
        
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {  
        if(head == NULL || head->next == NULL){  
            return head;  
        }  
        ListNode *p = new ListNode(-1);  
        p->next = head;  
        ListNode *cur = p, *pre = head;  
        while(pre != NULL){  
            bool isDupli = false;  
            while(pre->next != NULL && pre->val == pre->next->val){  
                isDupli = true;  
                pre = pre->next;  
            }  
            if(isDupli){  
                pre = pre->next;  
                continue;  
               
            }  
            cur->next = pre;  
            cur = cur->next;  
            pre = pre->next;  
              
        }  
        cur->next = pre;  
        return p->next;  
    } 
};