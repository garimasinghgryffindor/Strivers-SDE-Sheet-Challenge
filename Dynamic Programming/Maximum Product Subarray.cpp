// APPROACH 1
// using brute force
int maximumProduct(vector<int> &arr, int n)
{
	int res = INT_MIN;
	// finding all the subarrays and calculating products
	for(int i=0 ; i<n ; i++) {
		int prod = 1;
		for(int j=i ; j<n ; j++) {
			prod *=  arr[j];
			res = max(res, prod);
		}
	}

	return res;
}


// APPROACH 2
// using 2 Traversals
int maximumProduct(vector<int> &arr, int n)
{
	int maxLeft = arr[0], maxRight = arr[0];
	int prod = 1;
	bool zeroPresent = false;
	for(int x: arr) {
		prod *= x;
		if(x == 0) {
			prod = 1;
			zeroPresent = true;
			continue;
		}
		maxLeft = max(maxLeft, prod);
	}

	prod = 1;
	for(int i=n-1 ; i>=0 ; i--) {
		prod *= arr[i];
		if(arr[i] == 0) {
			prod = 1;
			zeroPresent = true;
			continue;
		}
		maxRight = max(maxRight, prod);
	}

	if(zeroPresent) return max(max(maxRight, maxLeft), 0);
	return max(maxRight, maxLeft);
}


