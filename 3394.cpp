#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int is_horizon_cut(vector<vector<int>>& rectangles, int y) {
        for (int i=0; i<rectangles.size(); i++) {
            if (rectangles[i][1] < y && rectangles[i][3] > y) return -1;
        }
        return y;
    }
    int is_vertical_cut(vector<vector<int>>& rectangles, int x) {
        for (int i=0; i<rectangles.size(); i++) {
            if (rectangles[i][0] < x && rectangles[i][2] > x) return -1;
        }
        return x;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int hor_cnt = 0, ver_cnt = 0;
        vector<bool> is_horizon(100005, 0);
        vector<bool> is_vertical(100005, 0);
        for (int i=0; i<rectangles.size(); i++) {
            int y1 = rectangles[i][1], y2 = rectangles[i][3];
            int x1 = rectangles[i][0], x2 = rectangles[i][2];
            if (y1 != 0 && y1 != n && is_horizon[y1] == 0 && is_horizon_cut(rectangles, y1) != -1) {
                hor_cnt++;
                is_horizon[y1] = 1;
            }
            if (y2 != 0 && y2 != n && is_horizon[y2] == 0 && is_horizon_cut(rectangles, y2) != -1 ) {
                hor_cnt++;
                is_horizon[y2] = 1;
            }
            if (x1 != 0 && x1 != n && is_vertical[x1] == 0 && is_vertical_cut(rectangles, x1) != -1) {
                ver_cnt++;
                is_vertical[x1] = 1;
            }
            if (x2 != 0 && x2 != n && is_vertical[x2] == 0 && is_vertical_cut(rectangles, x2) != -1) {
                ver_cnt++;
                is_vertical[x2] = 1;
            }
            if (hor_cnt >= 2 || ver_cnt >= 2) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int hor_cnt = 0, ver_cnt = 0;
        vector<bool> horizen(n, 0);
        vector<bool> vertical(n, 0);
        for (int i=0; i<rectangles.size(); i++) {
            for (int j=rectangles[i][0]+1; j<rectangles[i][2]; j++) {
                vertical[j] = 1;
            }
            for (int j=rectangles[i][1]+1; j<rectangles[i][3]; j++) {
                horizen[j] = 1;
            }
        }
        vector<int> horizen_cut_idx;
        vector<int> vertical_cut_idx;
        for (int i=1; i<n; i++) {
            if (vertical[i] == 0) vertical_cut_idx.push_back(i);
            if (horizen[i] == 0) horizen_cut_idx.push_back(i);
        }
        for (int i=0; i<horizen_cut_idx.size(); i++) {
            bool down = false, up = false;
            for (int j=0; j<rectangles.size(); j++) {
                if (rectangles[j][1] < horizen_cut_idx[i]) down = true;
                if (rectangles[j][1] >= horizen_cut_idx[i]) up = true;
                if (down && up) {
                    hor_cnt++;
                    break;
                } 
            }
            if (hor_cnt >= 2) return true;
        }
        for (int i=0; i<vertical_cut_idx.size(); i++) {
            bool left = false, right = false;
            for (int j=0; j<rectangles.size(); j++) {
                if (rectangles[j][0] < vertical_cut_idx[i]) left = true;
                if (rectangles[j][0] >= vertical_cut_idx[i]) right = true;
                if (left && right) {
                    ver_cnt++;
                    break;
                } 
            }
            if (ver_cnt >= 2) return true;
        }
        return false;
    }
};