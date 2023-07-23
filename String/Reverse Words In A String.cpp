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
