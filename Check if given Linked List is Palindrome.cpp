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
