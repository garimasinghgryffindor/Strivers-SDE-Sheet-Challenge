// using 2 stacks 
// making the enqueue operation costly

class Queue {
    // Define the data members(if any) here.
    stack<int>st1, st2;
    int size;
    public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(val);
        size++;
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int deQueue() {
        if(!size) {
            return -1;
        }
        int x = st1.top();
        st1.pop();
        size--;
        return x;
    }

    int peek() {
        if(!size) {
            return -1;
        }
        return st1.top();
    }

    bool isEmpty() {
        if(!size) {
            return true;
        }
        return false;
    }
};



// using 2 stacks 
// making the dequeue operation costly
class Queue {
    stack<int>st1, st2;
    int size;
    public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        st1.push(val);
        size++;
    }

    int deQueue() {
        // i need to fetch the last element of the stack i.e; first in
        
        if(!size) {
            return -1;
        }

        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int x = st2.top();
        st2.pop();

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        size--;
        return x;
    }

    int peek() {
        if(!size) {
            return -1;
        }

        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int x = st2.top();

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return x;
    }

    bool isEmpty() {
        return size==0;
    }
};



// using 2 stacks 
// optimal
class Queue {
    stack<int>st1, st2;
    int size;
    public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        st1.push(val);
        size++;
    }

    int deQueue() {
        // i need to fetch the last element of the stack i.e; first in
        
        if(!size) {
            return -1;
        }

        if(st2.empty())
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int x = st2.top();
        st2.pop();

        size--;
        return x;
    }

    int peek() {
        if(!size) {
            return -1;
        }
        
        if(st2.empty())
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    bool isEmpty() {
        return size==0;
    }
};


