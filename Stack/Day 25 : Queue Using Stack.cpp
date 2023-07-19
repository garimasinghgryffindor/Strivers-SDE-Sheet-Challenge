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
