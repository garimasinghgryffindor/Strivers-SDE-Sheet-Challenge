vector<vector<int>> pwset(vector<int>v)
{
    // using Bit Manipulation
    int n = v.size();
    int possibilities = pow(2,n);
    vector<vector<int>>res;
    for(int i=0 ; i<possibilities; i++) {
        int x = n;
        int num = i;
        vector<int>temp;
        while(x) {
            int tk_or_not = num&1;
            if(tk_or_not) {
                temp.push_back(v[x-1]);
            }
            num = num>>1;
            x--;
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    sort(res.begin(), res.end());
    return res;
}



void recur(vector<int>&v,int idx,int n,vector<vector<int>>&res,vector<int>temp) {
    if(idx == n) {res.push_back(temp); return;}

    // either i will not take that index
    recur(v,idx+1,n,res,temp);

    // or i will
    temp.push_back(v[idx]);
    recur(v,idx+1,n,res,temp);
}
vector<vector<int>> pwset(vector<int>v)
{
    // using RECURSION
    int n = v.size();
    sort(v.begin(), v.end());
    vector<vector<int>>res;
    recur(v,0,n,res,{});
    return res;
}

