// first two are by using two queues

// HERE I MADE THE PUSH OPERATION COSTLY O(N)
// AND POP O(N)

// SC -> O(N)
class Stack {

    queue<int>q1,q2;
    int size;
   public:
    Stack() {
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(size == 0)
            return true;
        return false;
    }

    void push(int element) { // O(N)
        q2.push(element);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        size++;
        swap(q1,q2);
    }

    int pop() { // O(1)
        if(!size) {
            return -1;
        }
        int x = q1.front();
        q1.pop();
        size--;
        return x;
    }

    int top() {
        if(!size) {
            return -1;
        }
        return q1.front();
    }
};



// POP OPERATION COSTLY

class Stack {

    queue<int>q1,q2;
    int size;
   public:
    Stack() {
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(size == 0)
            return true;
        return false;
    }

    void push(int element) {
        q1.push(element);
        size++;
    }

    int pop() {
        if(!size) {
            return -1;
        }
        int x;
        while(!q1.empty()) {
            x = q1.front();
            q1.pop();
            if(q1.empty()) {
                continue;
            }
            q2.push(x);
        }
        size--;
        swap(q1, q2);
        return x;
    }

    int top() {
        if(!size) {
            return -1;
        }
        int x;
        while(!q1.empty()) {
            x = q1.front();
            q1.pop();
            q2.push(x);
        }
        swap(q1, q2);
        return x;
    }
};
