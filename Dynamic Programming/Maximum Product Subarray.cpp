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



