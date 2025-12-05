#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int col = grid.size(), row = grid[0].size();
        int ans = 0;
        if (col == 1 && row == 1) return grid[0][0] == 0 ? 0 : 4 * grid[0][0] + 2;
        for (int i=0; i<col; i++) {
            for (int j=0; j<row; j++) {
                if (i == 0 || i == col-1) ans += grid[i][j];
                if (j == 0 || j == row-1) ans += grid[i][j];
                if (grid[i][j]) ans += 2;
                if (j > 0) ans += abs(grid[i][j] - grid[i][j-1]);
                if (i > 0) ans += abs(grid[i][j] - grid[i-1][j]);
            }
        }
        return ans;
    }
};