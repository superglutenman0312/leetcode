#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int col = obstacleGrid.size(), row = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[col-1][row-1]) return 0; 
        vector<vector<int>> dp(col, vector<int>(row, 0));
        dp[0][0] = 1;
        for (int i=1; i<row; i++) {
            if (obstacleGrid[0][i] == 0) dp[0][i] = dp[0][i-1];
            else dp[0][i] = 0;
        }
        for (int i=1; i<col; i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = dp[i-1][0];
            else dp[i][0] = 0;
        }
        for (int i=1; i<col; i++) {
            for (int j=1; j<row; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if (obstacleGrid[i][j]) dp[i][j] = 0;
            }
        }
        return dp[col-1][row-1];
    }
};