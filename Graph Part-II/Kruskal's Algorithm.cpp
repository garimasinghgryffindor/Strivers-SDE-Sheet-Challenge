// MST
class disjoint {
	vector<int> parent;
	public:
	disjoint(int n){
        parent.resize(n+1,-1);
    }

	int find(int x) {
		if (parent[x] < 0) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}

	void unionByWeight(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		if(pu != pv) {
			// that is both do not belong to the same component
			if(parent[pu] <= parent[pv]) {
				// i.e; parent[pu] is more negative
				parent[pu] += parent[pv];
				parent[pv] = pu;
			}
			else {
				parent[pv] += parent[pu];
				parent[pu] = pv;
			}
		}
	}
};

int kruskalMST(int n, vector<vector<int>> &graph)
{
	vector<pair<int,pair<int,int>>> edges;
	for(auto it: graph){
		int wt=it[2];
		int adjnode=it[1];
		int node=it[0];
		edges.push_back({wt,{node,adjnode}});
	}

	disjoint dis(n);
	sort(edges.begin(), edges.end());
	int cost = 0;

	for(auto it: edges) {
		int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
		if(dis.find(u) != dis.find(v)) {
			dis.unionByWeight(u, v);
			cost += wt;
		}
	}

	return cost;
}
