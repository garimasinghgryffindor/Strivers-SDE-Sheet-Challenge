#include <bits/stdc++.h>

void swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void percolateUp(vector<int>&heap) {
    int last = heap.size()-1;
    int parent = (last-1)/2;
    while(parent >= 0) {
        if(heap[parent] > heap[last]) {
            swap(heap[parent], heap[last]);
            last = parent;
            parent = (last-1)/2;
        } else {
            break;
        }
    }
}

void insert(vector<int>&heap,int x) {
    heap.push_back(x);
    percolateUp(heap);
}

void heapify(vector<int>&heap,int idx) {
    int n = heap.size();
    int c1 = 2*idx + 1;
    int c2 = 2*idx + 2;
    int minIdx = idx;
    if(c1 < n && heap[c1] < heap[minIdx]) {
        minIdx = c1;
    }
    if(c2 < n && heap[c2] < heap[minIdx]) {
        minIdx = c2;
    }

    if(minIdx != idx) {
        swap(heap[idx], heap[minIdx]);
        heapify(heap, minIdx);
    }
}

int removeMin(vector<int>&heap) {
    // swap the minimum with the last index
    int n = heap.size();
    int min = heap[0];
    swap(heap[0], heap[n-1]);
    heap.pop_back();
    // call heapify at the 0th index
    heapify(heap,0);
    return min;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>heap;
    vector<int>res;
    for(int i=0 ; i<n ; i++) {
        int x = q[i][0];
        if(x == 0) {
            insert(heap,q[i][1]);
        } else {
            int ans = removeMin(heap);
            res.push_back(ans);
        }
    }
    return res;
}
