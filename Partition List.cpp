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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l = &left, *r = &right;

        while(head){
            ListNode* & ref = head->val < x ? l : r;
            ref->next = head;
            ref = ref->next;
            
            head = head->next;
        }
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode node1(0), node2(0);
        ListNode *p1 = &node1, *p2 = &node2;
        while (head) {
            if (head->val < x)
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;
    }
};