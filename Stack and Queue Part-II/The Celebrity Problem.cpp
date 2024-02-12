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


// OPTIMAL
// using stack
int findCelebrity(int n) {
	stack<int>st;
	for(int i=0 ; i<n ; i++) {
		st.push(i);
	}

	while(st.size() > 1) {
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();

		if(!knows(a,b)) {
			st.push(a);
		} else {
			st.push(b);
		}
	}

	// to cross verify
	int potentialPerson = st.top();
	for(int i=0 ; i<n ; i++) {
		if(knows(potentialPerson, i)) {
			return -1;
		}

		if(i!=potentialPerson && !knows(i, potentialPerson)) {
			return -1;
		}
	}

	return potentialPerson;
}


// it's almost same
int findCelebrity(int n) {
 	stack<int>st;
	for(int i = 0; i < n; i++) st.push(i);

	while(st.size() > 1) {
		int a = st.top(); 	st.pop();
		int b = st.top(); 	st.pop();
		if(!knows(a,b)) {
			st.push(a);
		} else if(!knows(b, a)){
			st.push(b);
		}
	}

	if(st.empty()) return -1;

	int potentialCeleb = st.top();

	for(int i = 0; i < n; i++) {
		if(i != potentialCeleb) {
			if(!knows(i, potentialCeleb)) return -1;
			if(knows(potentialCeleb, i)) return -1;
		}
	}

	return potentialCeleb;
}
