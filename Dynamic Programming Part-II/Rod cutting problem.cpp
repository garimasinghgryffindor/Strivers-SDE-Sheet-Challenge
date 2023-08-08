
int recur(vector<int>&prices, int n, int idx, int prevCut) {
	if(idx > n) return 0;

	// either we will make cut at the current position
	int cutLength = idx-prevCut;
	int cutValue = prices[cutLength-1] + recur(prices, n, idx+1, idx);

	// or not
	int cutValue2 = recur(prices, n, idx+1, prevCut);

	return max(cutValue, cutValue2);
}

int cutRod(vector<int> &price, int n)
{
	return recur(price, n, 1, 0);
}
