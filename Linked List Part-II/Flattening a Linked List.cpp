Flattening a Linked List

Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of the next pointer.



Solution:

Approach 1: Brute Force
#define bottom child
// BRUTE FORCE APPROACH
// AS PER ME
Node *merge(Node*h1, Node*h2) {
    Node * dummy = new Node(0);
    dummy->bottom = h1;
    Node * temp1 = h2;
    Node * node = dummy->bottom;

    if(node->data > temp1->data) {
        Node * nxt = temp1->bottom;
        temp1->bottom = node;
        dummy->bottom = temp1;
        temp1 = nxt;
    }

    while(temp1) {
        node = dummy->bottom;

        while(node && node->bottom && temp1->data > node->bottom->data) {
            node = node->bottom;
        }
        if(node->bottom == NULL) {
            node->bottom = temp1;
            temp1 = temp1->bottom;
        } else if(temp1->data <= node->bottom->data) {
            Node * ptr = temp1->bottom;
            Node * ptr2 = node->bottom;
            node->bottom = temp1;
            temp1->bottom = ptr2;
            temp1 = ptr;
        }
    }
    return dummy->bottom;
}

Node *flattenLinkedList(Node *root)
{
   if(root == NULL || root->next == NULL) return root;
   Node* temp1 = root;
   Node* temp2 = root->next;
   while(temp2){
       temp1=merge(temp1,temp2);
       temp2=temp2->next;
   }
   Node* temp=temp1;
   while(temp){
       temp->next=NULL;
       temp=temp->bottom;
   }
   return temp1;
}



    
Approach 2:
Since each list, followed by the bottom pointer, are in sorted order. Our main aim is to make a single list in sorted order of all nodes. So, we can think of a merge algorithm of merge sort.


Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL)
        return root;
    
    Node * nxt = flatten(root->next);
    
    // using merge sort here
    Node * l1 = root, * l2 = nxt;
    Node * dummy = new Node(0);
    Node* temp = dummy;
    
    while(l1 && l2) {
        if(l1->data <= l2->data) {
            dummy->bottom = l1;
            l1 = l1->bottom;
        } else {
            dummy->bottom = l2;
            l2 = l2->bottom;
        }
        dummy = dummy->bottom;
    }
    
    while(l1) {
        dummy->bottom = l1;
        l1 = l1->bottom;
        dummy = dummy->bottom;
    }
    
    while(l2) {
        dummy->bottom = l2;
        l2 = l2->bottom;
        dummy = dummy->bottom;
    }
    
    return temp->bottom;
}
