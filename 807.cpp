#include<bits/stdc++.h>
using namespace std;

// N3
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        auto start = std::chrono::high_resolution_clock::now();
        int len = grid.size();
        int sum = 0;
        for (int i=0; i<len; i++) {
            int row_max = -1;
            for (int j=0; j<len; j++) {
                row_max = max(row_max, grid[i][j]);
            }
            for (int j=0; j<len; j++) {
                int col_max = -1;
                for (int k=0; k<len; k++) {
                    col_max = max(col_max, grid[k][j]);
                }
                sum += (min(row_max, col_max) - grid[i][j]);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        std::cout << "程式執行時間: " << duration.count() << " 毫秒" << std::endl;
        return sum;
    }
};

// 看能不能N2
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int len = grid.size();
        int sum = 0;
        vector<int> col_max;
        vector<int> row_max;
        int cur_max;
        for (int i=0; i<len; i++) {
            int cur_max = -1;
            for (int j=0; j<len; j++) {
                cur_max = max(cur_max, grid[i][j]);
            }
            row_max.push_back(cur_max);
        }
        for (int i=0; i<len; i++) {
            int cur_max = -1;
            for (int j=0; j<len; j++) {
                cur_max = max(cur_max, grid[j][i]);
            }
            col_max.push_back(cur_max);
        }
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                sum += (min(row_max[i], col_max[j]) - grid[i][j]);
            }
        }
        return sum;
    }
};
/*
[8, 4, 8, 7],
[7, 4, 7, 7],
[9, 4, 8, 7],
[3, 3, 3, 3]
*/