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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(0), *p = head;
        int sum = 0, dig = 0;
        int carry = 0;
        while(p1 != NULL && p2 != NULL)
        {
            sum = p1->val + p2->val + carry;
            carry = sum / 10;
            dig = sum % 10;
            ListNode * pNode = new ListNode(sum % 10);
            pNode->val = sum % 10;
            
            p->next = pNode;
            p = pNode;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != NULL)
        {
            sum = p1->val + carry;
            carry = sum / 10;
            dig = sum % 10;
            ListNode * pNode = new ListNode(sum % 10);
            pNode->val = sum % 10;
            
            p->next = pNode;
            p = pNode;
            p1 = p1->next;
        }
         while(p2 != NULL)
        {
            sum = p2->val + carry;
            carry = sum / 10;
            dig = sum % 10;
            ListNode * pNode = new ListNode(sum % 10);
            pNode->val = sum % 10;
            
            p->next = pNode;
            p = pNode;
            p2 = p2->next;
        }
        if (carry)
        {
            ListNode * pNode = new ListNode(carry);
            pNode->val = carry;
            p->next = pNode;
            p = pNode;
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};
