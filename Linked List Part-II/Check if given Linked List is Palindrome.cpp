Check if given Linked List is Palindrome

Solution: Using the extra data structure
Approach:

We can store elements in an array. Then check if the given array is a palindrome.

bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}



Solution 2: Optimized Solution
Approach:
Following are the steps to this approach:-
Find the middle element of the linked list. Refer to this article to know the steps https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
Reverse a linked list from the next element of the middle element. Refer to this article to know the steps https://takeuforward.org/data-structure/reverse-a-linked-list/
Iterate through the new list until the middle element reaches the end of the list.
Use a dummy node to check if the same element exists in the linked list from the middle element.


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode * newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next == NULL)
            return true;
        
        ListNode * slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // pointer to the starting of the second half of the linked list      
        ListNode * temp = slow->next;
        slow->next = NULL;
        fast = temp;
        // reversing the second half
        fast = reverse(fast);

        // pointer to the starting of the first half of the linked list
        slow = head;
        
        
        // checking whether it is palindrome or not
        while(fast && slow) {
            if(fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
    }
};



// 2nd way

// OPTIMIZED
// FINDING THE MIDDLE OF THE LINKED LIST
// SPLITTING THE LINKED LIST AT THE MID POINT
// REVERSING THE SECOND HALF OF THE LINKED LIST
// THEN CHECKING

LinkedListNode<int> * reverse(LinkedListNode<int> *head) {
    if(!head || !head->next)
        return head;


    LinkedListNode<int> *curr, *next, *prev;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    dummy->next = head;
    prev = dummy;
    curr = prev->next;
    next = curr->next;

    while(next) {
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = curr->next;
    }

    // print(dummy->next);
    return dummy->next;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next) {
        return true;
    }

    LinkedListNode<int> * curr = head;
    
    // We will tortoise-hare method to find the mid of the linked list
    LinkedListNode<int> * slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // head of the second half of the linked list
    LinkedListNode<int> * secondHalf = slow->next;
    slow->next = NULL;

    // reverse the second half
    LinkedListNode<int> *newHead = reverse(secondHalf);

    // checking palindrome
    LinkedListNode<int> *ptr1=head,*ptr2=newHead;
    while(ptr1 && ptr2) {
        if(ptr1->data != ptr2->data)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}



Solution 3:  Further Optimized Solution
Approach:

bool isPalindrome(ListNode* head) {
        ListNode * slow = head, *fast = head, *prev = NULL, *nextptr;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            nextptr = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextptr;
        }
        
        slow = fast ? slow->next : slow;
        
        while(slow) {
            if(slow->val != prev->val) {
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        return true; }
