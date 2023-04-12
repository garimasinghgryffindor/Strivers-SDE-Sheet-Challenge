Copy List with Random Pointer

Approach 1:
Brute Force

class Solution {
public:
    Node* copyRandomList(Node* head) {
	
//Step 1:  for every actual node I am creating a new Node and associating it to the original node   
 // using a Hashmap

        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;

//Step 2:  over here we are making all the connections

        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};




Optimal Approach:

Node* copyRandomList(Node* head) {
        Node * ptr = head;
        
        if(head == NULL)
            return NULL;
        
        while(ptr) {
            Node * node = new Node(ptr->val);
            // saving the next pointer
            Node * nxt = ptr->next;
            // making the new link
            ptr->next = node;
            // rejoining the next node to the newly created node
            node->next = nxt;
            
            ptr = ptr->next->next;
        }
        
        ptr = head;
        Node *newHead = head->next;
        Node *ptr2 = newHead;
        

        // making the random pointer connections
        while(ptr2) {
            if(ptr->random) {
                ptr2->random = ptr->random->next;
            }
            else {
                ptr2->random = NULL;
            }
            
            if(ptr2->next == NULL)
                break;
            
            ptr2 = ptr2->next->next;
            ptr = ptr->next->next;
        }
        
        
        // removing the remaking the connections  
        ptr = head, ptr2 = newHead;
        
        while(ptr2) {
            Node * nxt = ptr2->next;
            if(ptr2->next)
                ptr2->next = ptr2->next->next;
            ptr->next = nxt;
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        
        return newHead;
    }
