// BRUTE FORCE
int findCelebrity(int n) {
	int res = 0;
 	for(int i=0 ; i<n ; i++) {
		int everyOneKnows = 0;
		int flag = 0;
		for(int j=0 ; j<n ; j++) {
			if(i!=j) {
				if(!knows(i,j)) {
					if(knows(j,i)) {
						everyOneKnows++;
					}
				} else {
					flag = 1;
					break;
				}
			}
		}
		if(!flag && everyOneKnows) {
			return i; 
		}
	}
	return -1;
}
