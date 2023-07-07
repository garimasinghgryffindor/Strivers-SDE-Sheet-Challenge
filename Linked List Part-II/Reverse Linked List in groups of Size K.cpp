Reverse Linked List in groups of Size K

Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.



bool chkLength(ListNode * &ptr, int k){
        while(ptr!=NULL && k!=0){
            ptr = ptr->next;
            k--;
        }  
        if(k==0){
            return true;
        }
        
        return false;
    }
    
    ListNode * reverse(ListNode * ptr, int k){
        ListNode *curr,*prev,*currNext;
        if(k == 1){
            return ptr;
        }
        
        prev = ptr;
        curr = ptr->next;
        
        k--;
        while(curr != NULL && k!=0){
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
            k--;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * ptr = head;
        bool ret = chkLength(ptr, k);
        
        if(!ret){
            return head;
        }
        ListNode * rev = reverse(head, k);
        head->next = reverseKGroup(ptr,k);
        
        return rev;
    }




// 2nd way

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int getLength(Node *head) {
	int x = 0;
	while(head) {
		head = head->next;
		x++;
	}
	return x;
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]){

	if(head == NULL || head->next == NULL) {
		return head;
	}

	int block = b[0];
	int i=0;

	Node * dummy = new Node(0);
	dummy->next = head;

	Node *prev = dummy;
	Node * curr;
	Node * next;

	int length = getLength(head);

	while(prev && length && i<n) {
		curr = prev->next;

		if(b[i] == 0) {
			while(i<n && b[i]==0) {
				i++;
			}
			if(b[i]==0 || i==n) {
				break;
			}
		}

		block = b[i];
		if(block == 1) {
			prev = curr;
			length--;
			i++;
			continue;
		}

		if(curr == NULL || i == n) {
			break;
		}

		next = curr->next;
		while(block-1 && next) {
			block--;
			curr->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = curr->next;
		}
		length = max(0,length-b[i]);

		i++;
		prev = curr;
	}

	return dummy->next;
}



