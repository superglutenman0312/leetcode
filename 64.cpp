#include<bits/stdc++.h>
using namespace std;

// 額外開空間DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int col = grid.size(), row = grid[0].size();
        vector<vector<int>> dp(col, vector<int>(row));
        dp[0][0] = grid[0][0];
        for (int i=1; i<col; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int i=1; i<row; i++) dp[0][i] = dp[0][i-1] + grid[0][i];
        for (int i=1; i<col; i++) {
            for (int j=1; j<row; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[col-1][row-1];
    }
};

// 用O(1) space DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int col = grid.size(), row = grid[0].size();
        for (int i=1; i<col; i++) grid[i][0] = grid[i-1][0] + grid[i][0];
        for (int i=1; i<row; i++) grid[0][i] = grid[0][i-1] + grid[0][i];
        for (int i=1; i<col; i++) {
            for (int j=1; j<row; j++) {
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[col-1][row-1];
    }
};