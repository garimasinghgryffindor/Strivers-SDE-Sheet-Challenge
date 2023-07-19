#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int qfront;
    int rear;
    int size;
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        int ele = arr[qfront];
        qfront++;
        return ele;
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        return arr[qfront];
    }
};
