#include <bits/stdc++.h>

// MY FIRST APPROACH
// using PRIORITY QUEUE
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int>res;
	priority_queue<int, vector<int>, greater<int>>pq_min(arr.begin(), arr.end());

	int x = k;
	int minx = 0;
	while(x--) {
		minx = pq_min.top();
		pq_min.pop();
	}
	res.push_back(minx);

	priority_queue<int>pq_max(arr.begin(), arr.end());

	x = k;
	int maxx = 0;
	while(x--) {
		maxx = pq_max.top();
		pq_max.pop();
	}
	res.push_back(maxx);

	return res;
}


// NAIVE APPROACH
// FIRST SORT THE ARRAY AND THEN RETURN THE KTH MIN AND MAX ELEMENTS
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(), arr.end());
	return {arr[k-1], arr[n-k]};
}



// using Quickselect Algorithm
int partition(vector<int>&arr, int l, int r) {
	int last = arr[r];
	int i=l;
	for(int j=l ; j<=r-1 ; j++) {
		if(arr[j] < last) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[r],arr[i]);
	return i;
}

int kthSmall(vector<int>&arr, int l, int r, int k) {
	if(k <= r-l+1 && k>0) {
		int idx = partition(arr,l,r);
		if(idx - l == k-1) {
			return arr[idx];
		} else if(idx - l > k-1) {
			return kthSmall(arr,l,idx-1,k);
		} else {
			return kthSmall(arr,idx+1,r,k-(idx+1-l));
		}
	}
	return INT_MAX;
}


int partitionL(vector<int>&arr, int l, int r) {
	int last = arr[r];
	int i=l;
	for(int j=l ; j<=r-1 ; j++) {
		if(arr[j] > last) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[r],arr[i]);
	return i;
}

int kthLarge(vector<int>&arr, int l, int r, int k) {
	if(k <= r-l+1 && k>0) {
		int idx = partitionL(arr,l,r);
		if(idx - l == k-1) {
			return arr[idx];
		} else if(idx - l > k-1) {
			return kthLarge(arr,l,idx-1,k);
		} else {
			return kthLarge(arr,idx+1,r,k-(idx+1-l));
		}
	}
	return INT_MAX;
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	int kthSmallest = kthSmall(arr,0,n-1,k);
	int kthLargest = kthLarge(arr,0,n-1,k);
	return {kthSmallest, kthLargest};
}



