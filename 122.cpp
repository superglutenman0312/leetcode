#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0], profit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i-1] < prices[i]) {
                buy_price = prices[i-1];
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};