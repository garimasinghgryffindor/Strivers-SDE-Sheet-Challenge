// VARIATION OF MCM PROBLEM
int eggDrop(int n, int k) 
{
    if(k == 0 || k == 1) return k;
    if(n == 1) return k;
    
    int mn = INT_MAX;
    for(int i = 1; i <= k; i++) {
        int ifBreaks = 1 + eggDrop(n-1, i-1);
        int ifNotBreaks = 1 + eggDrop(n, k-i);
        int breaks = max(ifBreaks, ifNotBreaks); // in worst case
        mn = min(breaks, mn);
    }
    
    return mn;
}
