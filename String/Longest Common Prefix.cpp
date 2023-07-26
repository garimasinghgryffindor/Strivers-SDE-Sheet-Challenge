
// NAIVE APPROACH
// CHECK ITERATIVELY
// TIME COMPLEXITY : O(min(LenOfString)*n)
string longestCommonPrefix(vector<string> &arr, int n)
{
    // maximum length of ending index of prefix could be the minimum of all the strings
    int maxLen = INT_MAX;
    for(auto x: arr) {
        if(x.length() < maxLen) {
            maxLen = x.length();
        }
    }

    string ans = "";
    for(int i=0 ; i<maxLen ; i++) {
        // check iteratively for all the strings
        int ithOfFirst = arr[0][i];
        bool flag = true;
        for(int j=1 ; j<n ; j++) {
            if(arr[j][i] != ithOfFirst) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            return ans;
        } else {
            ans += ithOfFirst;
        }
    }

//     return ans;
// }



// SHORTER CODE
// USING SORTING
// TIME COMPLEXITY :  O((N*S*LOGN) for Sorting *(minLenOfString(S))
string longestCommonPrefix(vector<string> &arr, int n)
{
    sort(arr.begin(), arr.end());
    string ans ="";
    string first = arr[0], last = arr[n-1];
    for(int i=0 ; i<first.length() ; i++) {
        if(first[i] == last[i]) {
            ans += first[i];
        } else {
            return ans;
        }
    }
    return ans;
}


