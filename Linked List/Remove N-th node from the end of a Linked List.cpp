Remove N-th node from the end of a Linked List

Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.


Solution 1: Naive Approach [Traverse 2 times]


Solution 2: [Efficient] Two pointer Approach

Intuition : 
What if we had to modify the same above approach to work in just one traversal? Let’s see what all information we have here:
We have the flexibility of using two-pointers now.
We know, that the n-th node from the end is the same as (total nodes – n)th node from start.
But, we are not allowed to calculate total nodes, as we can do only one traversal.
What if, one out of the two-pointers is at the nth node from start instead of the end? Will it make anything easier for us?
Yes, with two pointers in hand out of which one is at the n-th node from start, we can just advance both of them till the end simultaneously, once the faster reaches the end, the slower will stand at the n-th node from the end.
Approach : 
Take two dummy nodes, who’s next will be pointing to the head.
Take another node to store the head, initially,s a dummy node(start), and the next node will be pointing to the head. The reason why we are using this extra dummy node is that there is an edge case. If the node is equal to the length of the LinkedList, then this slow will point to slow’s next→ next. And we can say our dummy start node will be broken and will be connected to the slow next→ next.
Start traversing until the fast pointer reaches the nth node.
Now start traversing by one step both of the pointers until the fast pointers reach the end.    
When the traversal is done, just do the deleting part. Make slow pointers next to the next of the slow pointer to ignore/disconnect the given node.
Last, return to the next start.


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * fast = dummy, *slow = dummy;
        int x = n;
        while(x--) {
            fast = fast->next;
        }
        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
