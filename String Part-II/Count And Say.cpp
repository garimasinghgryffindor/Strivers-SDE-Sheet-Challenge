#include <bits/stdc++.h> 
// NAIVE APPROACH
string writeAsYouSpeak(int n) 
{
	int i = 1;
	string res= "1";
	if(n == i) {
		return res;
	}

	i++;
	res = "11";

	if(n == i)
		return res;

	while(i < n) {
		string newString = "";
		int freq = 1;
		for(int j = 1 ; j<res.length() ; j++) {
			if(res[j] == res[j-1]) {
				freq++;
			} else {
				char st = (char)('0'+freq);
				newString += string(1,st) + string(1,res[j-1]);
				freq = 1;
			}

			if(j == res.length()-1) {
				char st = (char)('0'+freq);
				newString += string(1,st) + string(1,res[j]);
			}
		}
		res = newString;
		i++;
	}

	return res;
}
