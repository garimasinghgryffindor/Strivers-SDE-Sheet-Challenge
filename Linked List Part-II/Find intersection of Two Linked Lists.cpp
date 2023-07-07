Find intersection of Two Linked Lists

Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.


Solution 1: Brute-Force
Approach: We know intersection means a common attribute present between two entities. Here, we have linked lists as given entities. 
Keep any one of the list to check its node present in the other list. Here, we are choosing the second list for this task.
Iterate through the other list. Here, it is the first one. 
Check if the both nodes are the same. If yes, we got our first intersection node.
If not, continue iteration.
If we did not find an intersection node and completed the entire iteration of the second list, then there is no intersection between the provided lists. Hence, return null.

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}






Solution 2: Hashing
Approach:
Can we improve brute-force time complexity? In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-
Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
Iterate through list 2 and search the hashed value in the hash table. If found, return node.


node* intersectionPresent(node* head1,node* head2) {
    unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

}




Solution 3: Difference in length
Approach:
We will reduce the search length. This can be done by searching the length of the shorter linked list. How? Let’s see the process.
Find the length of both lists.
Find the positive difference between these lengths.
Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2=0;
        ListNode * temp1 = headA, *temp2 = headB;
        while(temp1) {
            len1++;
            temp1=temp1->next;
        }
        while(temp2) {
            len2++;
            temp2=temp2->next;
        }
        
        int flag = 0;
        if(len1-len2 >= 0) {
            
        } else {
            flag = 1;
        }
        
        ListNode * ptr, *ptr2;
        if(flag) {
            ptr = headB;
            ptr2 = headA;
        } else {
            ptr = headA;
            ptr2 = headB;
        }
        
        int diff = abs(len1-len2);
        
        while(diff--) {
            ptr = ptr->next;
        }
        
        while(ptr && ptr2) {
            if(ptr == ptr2) {
                return ptr;
            }
            
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        
        return NULL;
        
    }
};




Solution 4: Optimised 
Approach:
The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.



node* intersectionPresent(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}
