#include <bits/stdc++.h>

// // NAIVE APPROACH
// void findMedian(int *arr, int n)
// {
//     vector<int>res;
//     priority_queue<int>pq;
//     for(int i=0 ; i<n ; i++) {
//         pq.push(arr[i]);
//         vector<int>temp;
//         int x = i/2;
//         while(x--) {
//             temp.push_back(pq.top());
//             pq.pop();
//         }
//         if((i+1)%2 == 0) {
//             // even
//             int x1 = pq.top();
//             temp.push_back(x1);
//             pq.pop();
//             int x2 = pq.top();
//             int median = (x1 + x2)/2;
//             res.push_back(median);
//         } else {
//             // odd
//             int x1 = pq.top();
//             res.push_back(x1);
//         }

//         for(auto x: temp) {
//             pq.push(x);
//         }
//     }

//     for(int i=0 ; i<n ; i++) {
//         cout<<res[i]<<" ";
//     }
// }



// OPTIMAL APPROACH
void findMedian(int *arr, int n)
{
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int> >minh;
    for(int i=0 ; i<n ; i++) {
        if(maxh.empty() || maxh.top() >= arr[i]) {
            maxh.push(arr[i]);
        } else {
            minh.push(arr[i]);
        }

        if(maxh.size() > minh.size() + 1) {
            minh.push(maxh.top());
            maxh.pop();
        } else if(maxh.size() < minh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }

        if(minh.size() < maxh.size()) {
            cout<<maxh.top()<<" ";
        } else {
            cout<<(minh.top() + maxh.top())/2<<" ";
        }
    }
}

// greatest  // smallest
// maxh => 1 2 3 4
// minh => 8 7 6 5




