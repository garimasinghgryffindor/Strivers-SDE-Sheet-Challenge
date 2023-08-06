
// RECURSION
int recur(vector<int>&rack, int idx, int prevWeight) {
	if(idx >= rack.size()) return 0;

	int take = 0, notTake = 0;
	if(rack[idx] > prevWeight) {
		take = rack[idx] + recur(rack, idx+1, rack[idx]);
	}

	notTake = 0 + recur(rack, idx+1, prevWeight);

	return max(take, notTake);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	return recur(rack, 0, 0);
}
