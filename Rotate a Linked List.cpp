Rotate a Linked List

Problem Statement: Given the head of a linked list, rotate the list to the right by k places.


Solution: Brute Force
Approach:
We have to move the last element to first for each k.
For each k, find the last element from the list. Move it to the first.


// brute force
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next) {
            return head;
        }
        
        int count = 0;
        ListNode * temp = head;
        while(temp) {
            temp = temp->next;
            count++;
        }
        
        k%=count;
        
        // k times find the last node and put them to the starting of the list
        ListNode * tempHead = head;
        
        while(k--) {
            ListNode * temp = tempHead;
            while(temp->next!=NULL && temp->next->next!=NULL) {
                temp = temp->next;
            }
            ListNode* nxtptr = temp->next;
            nxtptr->next = tempHead;
            temp->next = NULL;
            tempHead = nxtptr;
        }
        
        return tempHead;
    }
};




Solution: Optimal Solution
Approach:
Steps to the algorithm:-
Calculate the length of the list.
Connect the last node to the first node, converting it to a circular linked list.
Iterate to cut the link of the last node and start a node of k%length of the list rotated list.



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp=head , *temp2=head;
        
        if(!head || !head->next) return head;
        
        int cnt=1;
        while(temp2->next){
            temp2=temp2->next;
            cnt++;
        }
        //link last node to first node
        temp2->next = head;
        
        int x=k%cnt;
        int end = cnt-x;
        
        while(end--){
            temp2=temp2->next;
        }
        
        temp = temp2->next;
        temp2->next = NULL;
        
        return temp;
    }
};
