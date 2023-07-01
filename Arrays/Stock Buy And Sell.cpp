Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Solution 1: Brute Force
Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
          }
        }
      }

    return maxPro;
}

Solution 2: Optimal solution 
Intuition: We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0;
        for(int i=1 ; i<prices.size() ; i++) {
            int profitHere = prices[i] - mini;
            profit = max(profit, profitHere);
            mini = min(mini, prices[i]);
        }
        
        return profit;
    }
};
