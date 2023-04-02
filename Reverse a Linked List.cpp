Reverse a Linked List

Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

  
  
Reverse Linked List: Iterative:

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *nextNode;
        while(head) {
            nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    

Reverse a Linked List: Recursive:

ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;  }
