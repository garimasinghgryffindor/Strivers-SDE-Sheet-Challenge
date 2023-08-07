#include <bits/stdc++.h>
// USING RECURSION
int recur(int *denominations, int target, int idx) {
    if(target == 0) return 1;
    if(idx < 0) return 0;

    int notTake = recur(denominations, target, idx-1);
    int take = 0;
    if(target >= denominations[idx]) {
        take = recur(denominations, target-denominations[idx], idx);
    }
    return take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return recur(denominations, value, n-1);
}
