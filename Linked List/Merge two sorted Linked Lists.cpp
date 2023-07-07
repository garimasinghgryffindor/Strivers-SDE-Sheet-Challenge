Merge two sorted Linked Lists

Solution 1: Using an externally linked list to store answers. 

Step 1: Create a new dummy node. It will have the value 0 and will point to NULL respectively. This will be the head of the new list. Another pointer to keep track of traversals in the new list.
Step 2:  Find the smallest among two nodes pointed by the head pointer of both input lists, and store that data in a new list created.
Step 3: Move the head pointer to the next node of the list whose value is stored in the new list.
Step 4: Repeat the above steps till any one of the head pointers stores NULL. Copy remaining nodes of the list whose head is not NULL in the new list.


Solution 2: Inplace method without using extra space.
Approach :
Step 1: Create two pointers, say l1 and l2. Compare the first node of both lists and find the small among the two. Assign pointer l1 to the smaller value node.
Step 2: Create a pointer, say res, to l1. An iteration is basically iterating through both lists till the value pointed by l1 is less than or equal to the value pointed by l2.
Step 3: Start iteration. Create a variable, say, temp. It will keep track of the last node sorted list in an iteration. 
Step 4: Once an iteration is complete, link node pointed by temp to node pointed by l2. Swap l1 and l2.
Step 5: If any one of the pointers among l1 and l2 is NULL, then move the node pointed by temp to the next higher value node.




My Solution:
(Using modified merge sort)


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * newList = new ListNode() , *iter1 = list1, *iter2 = list2;
        ListNode* curr = newList;
        
        while(iter1!=NULL && iter2!=NULL) {
            if(iter1->val <= iter2->val) {
                curr->next = iter1;
                iter1 = iter1->next;
            }
            else {
                curr->next = iter2;
                iter2 = iter2->next;
            }
            curr=curr->next;
        }
        
        while(iter1!=NULL) {
            curr->next = iter1;
            iter1 = iter1->next;
            curr=curr->next;
        }
        
        while(iter2!=NULL) {
            curr->next = iter2;
            iter2 = iter2->next;
            curr = curr->next;
        }
        
        return newList->next;
    }

