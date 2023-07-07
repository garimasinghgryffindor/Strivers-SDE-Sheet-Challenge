Starting point of loop in a Linked List

Solution 1: Brute Force
Approach:
We can store nodes in a hash table so that, if a loop exists, the head will encounter the same node again. This node will be present in the table and hence, we can detect the loop. The steps are:-
Iterate the given list.
For each node visited by the head pointer, check if the node is present in the hash table.
If yes, the loop detected
If not, insert the node in the hash table and move the head pointer ahead.
If the head reaches null, then the given list does not have a cycle in it.


ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head ;
        unordered_map<ListNode* , int> mp;
        //             pointer    count
        
         while(temp!=NULL){
            if(!mp.empty() && mp.find(temp) != mp.end()){
                    return temp;
            }
            mp[temp]++;
            temp = temp->next;
        }
        
        return NULL;
    }





Solution 2: Slow and Fast Pointer Method
Approach:
The following steps are required:
Initially take two pointers, fast and slow. The fast pointer takes two steps ahead while the slow pointer will take a single step ahead for each iteration.
We know that if a cycle exists, fast and slow pointers will collide.
If the cycle does not exist, the fast pointer will move to NULL
Else, when both slow and fast pointer collides, it detects a cycle exists.
Take another pointer, say entry. Point to the very first of the linked list.
Move the slow and the entry pointer ahead by single steps until they collide. 
Once they collide we get the starting node of the linked list.
But why use another pointer, or xentry?
Let’s say a slow pointer covers the L2 distance from the starting node of the cycle until it collides with a fast pointer. L1 is the distance traveled by the entry pointer to the starting node of the cycle. So, in total, the slow pointer covers the L1+L2 distance. We know that a fast pointer covers some steps more than a slow pointer. Therefore, we can say that a fast pointer will surely cover the L1+L2 distance. Plus, a fast pointer will cover more steps which will accumulate to nC length where cC is the length of the cycle and n is the number of turns. Thus, the fast pointer covers the total length of L1+L2+nC. 
We know that the slow pointer travels twice the fast pointer. So this makes the equation to
2(L1+L2) = L1+L2+nC. This makes the equation to
L1+L2 = nC. Moving L2 to the right side
L1 = nC-L2 and this shows why the entry pointer and the slow pointer would collide.





ListNode *detectCycle(ListNode *head) {
        // using slow and fast pointer
        
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode * slow = head, *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                fast = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }

