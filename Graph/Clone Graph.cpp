graphNode *cloneGraph(graphNode *node)
{
    if(!node) return node;
	graphNode * res = new graphNode(node->data, {});
	unordered_map<graphNode*, graphNode*>clone;
	clone[node] = res;
	queue<graphNode*> q;
	q.push(node);
	while(!q.empty()) {
		graphNode * curr = q.front();
		q.pop();
		for(auto ptr: curr->neighbours) {
			if(clone.find(ptr) == clone.end()) {
				clone[ptr] = new graphNode(ptr->data, {});
				q.push(ptr);
			}
			clone[curr]->neighbours.push_back(clone[ptr]);
		} 
	}

	return res;
}
