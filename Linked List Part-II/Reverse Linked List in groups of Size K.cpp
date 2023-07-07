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
