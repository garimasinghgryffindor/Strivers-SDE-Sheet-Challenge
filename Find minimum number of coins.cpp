Find minimum number of coins

Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.


int findMinimumCoins(int amount) 
{
    int am = amount;
    vector<int> currency{1000,500,100,50,20,10,5,2,1};
    int res = 0;
    for(auto x: currency) {
        if(am/x != 0) {
            res += am/x;
            am = am%x;
        }
    }

    return res;
}
