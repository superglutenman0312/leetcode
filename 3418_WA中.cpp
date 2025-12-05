#include<bits/stdc++.h>
using namespace std;

// 二維DP -> 失敗
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int col = coins.size(), row = coins[0].size();
        vector<vector<int>> dp(col, vector<int>(row, -1005));
        vector<vector<char>> from(col, vector<char>(row, 'N')); // U L
        vector<int> path;
        dp[0][0] = coins[0][0];
        for (int i=1; i<col; i++) {
            dp[i][0] = dp[i-1][0] + coins[i][0];
            from[i][0] = 'U';
        }
        for (int i=1; i<row; i++) {
            dp[0][i] = dp[0][i-1] + coins[0][i];
            from[0][i] = 'L';
        }
        for (int i=1; i<col; i++) {
            for (int j=1; j<row; j++) {
                if (dp[i-1][j] >= dp[i][j-1]) from[i][j] = 'U';
                else from[i][j] = 'L';
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + coins[i][j];
            }
        }
        int x = col-1, y = row-1;
        while (x >= 0 && y >= 0) {
            path.push_back(coins[x][y]);
            if (from[x][y] == 'U') x -= 1;
            else y -= 1;
        }
        sort(path.begin(), path.end());
        int ans = dp[col-1][row-1];
        if (path.size() > 0 && path[0] < 0) ans += abs(path[0]);
        if (path.size() > 1 && path[1] < 0) ans += abs(path[1]);
        return ans;
    }
};

// 3維DP -> 失敗，我頭好痛，耖，什麼拉機題目，難度才medium，騙鬼吧
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int INF = -1e9;
        int col = coins.size(), row = coins[0].size();
        vector<vector<vector<int>>> dp(col, vector<vector<int>>(row, vector<int>(3, INF)));
        // dp[x][y][z] 代表 在還有z次彌平機會時，到達該點的最大獲利。
        dp[0][0][2] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
            dp[0][0][0] = 0;
        }
        else {
            dp[0][0][1] = coins[0][0];;
            dp[0][0][0] = coins[0][0];;
        }
        for (int i=1; i<col; i++) {
            for (int j=0; j<=2; j++) {
                // 不彌平
                dp[i][0][j] = dp[i-1][0][j] + coins[i][0];
                // 彌平
                if (coins[i][0] < 0 && j > 0) dp[i][0][j] = max(dp[i][0][j], dp[i-1][0][j-1]);
            }
        }
        for (int i=1; i<row; i++) {
            for (int j=0; j<=2; j++) {
                dp[0][i][j] = dp[0][i-1][j] + coins[0][i];
                if (coins[0][i] < 0 && j > 0) dp[0][i][j] = max(dp[0][i][j], dp[0][i-1][j-1]);
            }
        }
        for (int i=1; i<col; i++) {
            for (int j=1; j<row; j++) {
                for (int k=0; k<=2; k++) {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]) + coins[i][j];
                    if (coins[i][j] < 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k-1], dp[i][j-1][k-1]));
                }
            }
        }
        int ans = max(dp[col-1][row-1][2], dp[col-1][row-1][1]);
        ans = max(ans, dp[col-1][row-1][0]);
        return ans;
    }
};


/*
0  1 -1
1 -2  3
2 -3  4

0  1 0 
1 -1 3 
3  0 7 
*/