// using quick sort
void swap(int &a,int &b) {
	int x = a;
	a = b;
	b = x;
}

int partition(vector<int>&arr, int l, int r) {
	int pivot = arr[r];
	int i = l-1;
	for(int j=l ; j<=r ; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}

int quicksort(vector<int>&arr, int l, int r, int target) {
	if(l < r) {
		int p = partition(arr,l,r);
		if(p == target) {
			return arr[p];
		} else if(p < target) {
			return quicksort(arr,p+1, r, target);
		} else {
			return quicksort(arr, l, p-1, target);
		}
	}
	return arr[l];
}

int kthLargest(vector<int>& arr, int size, int K)
{
	int targetIndex = size-K;

	return quicksort(arr,0,size-1,targetIndex);

}
