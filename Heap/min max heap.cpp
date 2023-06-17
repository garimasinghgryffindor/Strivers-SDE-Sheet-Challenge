Min Heap/Max Heap

#include <iostream>
#define MAX 100
using namespace std;

void heapify(int arr[],int n , int i)
{
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if(c1<n && arr[c1]>arr[max])
    {
        max=c1;
    }

    if(c2<n && arr[c2]>arr[max])
    {
        max=c2;
    }

    if(max!=i)
    {
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;

        heapify(arr,n,max);
    }
}

void buildHeap(int arr[],int n)
{
    for(int i=n/2-1 ; i>=0 ; i--)
    {
        heapify(arr,n,i);
    }
}

void extract_max(int arr[],int n)
{
    int temp=arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=temp;
    n--;

    buildHeap(arr,n);
}

void heapSort(int arr[],int n)
{
    int cap=n;
    while(cap>=1)
    {
        buildHeap(arr,n);
        extract_max(arr,n);
        n--;
        cap--;
    }
}

int main()
{
    int n;
    int arr[MAX];
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i =0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    buildHeap(arr,n);

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    extract_max(arr,n);
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    heapSort(arr,n);
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}



#include <bits/stdc++.h> 

void swap(int&a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>&heap,int index) {
    int c1 = 2*index + 1;
    int c2 = 2*index + 2;
    int n = heap.size();
    int minidx = index;

    if(c1 < n && heap[c1] < heap[minidx]) {
        minidx = c1;
    }
    if(c2 < n && heap[c2] < heap[minidx]) {
        minidx = c2;
    }

    if(minidx != index) {
        swap(heap[minidx], heap[index]);
        heapify(heap, minidx);
    }
}

void insert(vector<int>&heap, int x) {
    heap.push_back(x);
    int idx = heap.size()-1;
    int par = (idx-1)/2;
    while(heap[par] > heap[idx]) {
        heapify(heap,par);
        idx = par;
        par = (par - 1)/2;
    }

}

void buildHeap(vector<int>&heap) {
    int n = heap.size();

    for(int i=n/2-1 ; i>=0 ; i--) {
        heapify(heap,i);
    }
}

int minimum(vector<int>&heap) {
    int ans = heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    buildHeap(heap);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap;
    vector<int>res;

    for(int i=0 ; i<n ; i++) {
        if(q[i][0] == 0) {
            insert(heap,q[i][1]);
        } else {
            int min = minimum(heap);
            res.push_back(min);
        }
    }

    return res;
}
