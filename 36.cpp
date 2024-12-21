#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_row_valid(vector<char>& row) {
        int check[10] = {0};
        for (int i=0; i<row.size(); i++) {
            if ('1' <= row[i] && row[i] <= '9') check[row[i]-'0']++;
            if (check[row[i]-'0'] > 1) return false;
        }
        return true;
    }
    bool is_col_valid(vector<vector<char>>& col, int k) {
        int check[10] = {0};
        for (int i=0; i<col.size(); i++) {
            if ('1' <= col[i][k] && col[i][k] <= '9') check[col[i][k]-'0']++;
            if (check[col[i][k]-'0'] > 1) return false;
        }
        return true;
    }
    bool is_block_valid(vector<int>& block) {

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            if (is_row_valid(board[i]) == false) return false;
            if (is_col_valid(board, i) == false) return false;
        }
        int row_cnt = 0, col_cnt = 0;
        vector<int> block;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board.size(); j++) {
                if ('1' <= board[i][j] && board[i][j] <= '9') block.push_back(board[i][j]-'0');
                row_cnt++;
                if (row_cnt == 3 * ((i/3) + 1)) break;
            }
            col_cnt++;
            if (col_cnt == 3) {
                if (is_block_valid(block) == false) return false;
                row_cnt = 
            }
        }
    }
};