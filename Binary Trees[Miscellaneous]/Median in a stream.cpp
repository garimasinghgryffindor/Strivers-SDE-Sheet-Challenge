#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	vector<int>res;
	priority_queue<int>left;
	priority_queue<int, vector<int>, greater<int>> right;

	for(int i=0 ; i<n ; i++) {
		if(left.empty()) {
			left.push(arr[i]);
		} else {
			int tp = left.top();
			if(arr[i] <= tp) {
				// push in the left array
				left.push(arr[i]);
                        } else {
                          right.push(arr[i]);
                        }
                }

                        if(right.size() > left.size()) {
				int tp = right.top();
				right.pop();
				left.push(tp);
			} else if(left.size() > right.size() + 1) {
				int tp = left.top();
				left.pop();
				right.push(tp);
			}

			int ans = left.top();
			if(right.size() == left.size()) {
				ans += right.top();
				ans = ans/2;
			}
			
			res.push_back(ans);
		
	}

	return res;
}
