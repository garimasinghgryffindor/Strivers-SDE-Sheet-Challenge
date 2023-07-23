// normal approach
// iterative
string reverseString(string &str){
	int n = str.length();
	string ans = "";
	string temp = "";
	for(int i=0 ; i<n ; i++) {
		if(str[i]==' ' && i>0 && str[i-1]==' ')
			continue;
		if(str[i] == ' ') {
			if(ans == "") {
				ans = temp;
			} else {
				ans = temp + " " + ans;
			}
			temp = "";
		} else {
			temp += str[i];
		}
	}

	if(temp != "") {
		ans = temp + " " + ans;
	}

	return ans;
}



// using vector
string reverseString(string &str){
	vector<string>vec;
	string ans = "";
	int n = str.length();
	for(int i=0 ; i<n ; i++) {
		string temp = "";
		while(!isspace(str[i]) && i<n) {
			temp.push_back(str[i++]);
		}
		if(!temp.empty()) {
			vec.push_back(temp);
		}
	}

	for(int i=vec.size()-1 ; i>=0 ; i--) {
		ans.append(vec[i]);
		if(i>0) {
			ans.append(" ");
		}
	}

	return ans;
}
