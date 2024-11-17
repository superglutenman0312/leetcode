#include<bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int max_profit = 0;
        for (int i=0; i<prices.size(); i++){
            for (int j=0; j<prices.size(); j++){
                if(prices[j] - prices[i] > max_profit && j>i) max_profit = prices[j] - prices[i];
            }
        }
        return max_profit;
    }
};
 
// O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int max_profit = 0, buy_price = prices[0];
        for (int i=0; i<prices.size(); i++){
            if (buy_price > prices[i]) buy_price = prices[i];
            int potential_profit = prices[i] - buy_price;
            if (potential_profit > max_profit) max_profit = potential_profit;
        }
        return max_profit;
    }
};


