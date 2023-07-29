#include <bits/stdc++.h> 

// oohh interesting

int recur(vector<int>inorder,vector<int>levelOrder,int l,int r, int n) {
	if (l == r)
        return 0;

	int root = levelOrder[0];

	auto it = find(inorder.begin(), inorder.end(), root);
	if(it == inorder.end()) return 0;
	
	int idx = it - inorder.begin();

	int leftCount = idx - l;
    int rightCount = r - idx;

	vector<int>newLeftLevel(leftCount);
	vector<int>newRightLevel(rightCount);
 
	int k = 0;
	for (int i = 0; i < n ; i++) {
        for (int j = l; j < idx ; j++) {
            if (levelOrder[i] == inorder[j]) {
                newLeftLevel[k] = levelOrder[i];
                k++;
                break;
            }
        }
    }
 
    k = 0;
	for (int i = 0 ; i < n ; i++) {
        for (int j = idx + 1; j <= r; j++) {
            if (levelOrder[i] == inorder[j]) {
                newRightLevel[k] = levelOrder[i];
                k++;
                break;
            }
        }
    }

	int left=0, right=0;

	if(leftCount > 0 ) {
		left = recur(inorder,newLeftLevel,l,idx-1,leftCount);
	}

	if(rightCount > 0) {
		right = recur(inorder,newRightLevel,idx+1,r,rightCount);
	}

	return (1 + max(left, right));
}

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	int ans = recur(inorder,levelOrder,0,N-1,N);

	return ans;
}

// level -> 1 2 3 4 5
// inorder -> 4 2 5 1 3 
// 	   1
//    2 3
//  4 7 5 6


// OPTIMAL
class Temp {
public:
    int height;
    int leftIndex;
    int rightIndex;

    Temp(int h, int li, int ri) {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    int maxHeight = 0;
    queue<Temp> q;

    if(N >= 1) {
        Temp temp(0, 0, N - 1);
        q.push(temp);
    }
    unordered_map<int, int> map;
    for(int i = 0;i < N; i++) {
        map[inorder[i]] = i;
    }

    for(int i = 0;i < N; i++) {
        Temp temp = q.front();
        q.pop();

        maxHeight = max(temp.height, maxHeight);

        int li = temp.leftIndex;
        int ri = temp.rightIndex;
        int rootIndex;

        rootIndex = map[levelOrder[i]];

        if(rootIndex - 1 >= li) {
            Temp leftSubTree(temp.height + 1, li, rootIndex - 1);
            q.push(leftSubTree);
        }

        if(rootIndex + 1 <= ri) {
            Temp rightSubTree(temp.height + 1, rootIndex + 1, ri);
            q.push(rightSubTree);
        }
    }

    return maxHeight;
}


