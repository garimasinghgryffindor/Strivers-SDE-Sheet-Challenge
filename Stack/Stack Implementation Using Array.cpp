// Stack class.
class Stack {
    
public:
    vector<int>st;
    int cap;
    int last;
    Stack(int capacity) {
        st.resize(capacity);
        last = -1;
        cap = capacity;
    }

    void push(int num) {
        if(last == cap-1) {
            // stack is full
            // cannot push
        } else {
            st[last+1] = num;
            last++;
        }
    }

    int pop() {
        if(last == -1) {
            // stack is empty
            // cannot pop
        } else {
            int topEle = st[last];
            last--;
            return topEle;
        }
        return -1;
    }
    
    int top() {
        if(last == -1) {
            // stack is empty
        } else {
            int topEle = st[last];
            return topEle;
        }
        return -1;
    }
    
    int isEmpty() {
        if(last == -1) {
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(last == cap-1) {
            return 1;
        }
        return 0;
    }
    
};
