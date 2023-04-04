Add two numbers represented as Linked Lists

Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.


Solution 1: Elementary Math
Intuition: Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of the list, which contains the least significant digit.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode();
        ListNode * ptr = dummy;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=carry;
            carry = sum/10;
            sum%=10;
            ptr->next = new ListNode(sum);
            ptr=ptr->next;
        }
        
        return dummy->next;
    }
};



