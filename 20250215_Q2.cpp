#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double target = 0;
        double low = 2e9, high = 0, mid = 0;
        for (int i=0; i<squares.size(); i++) {
            target += (squares[i][2] * squares[i][2]) / 2;
            if (squares[i][1] < low) low = squares[i][1];
            if (squares[i][1] + squares[i][2] > high) high = squares[i][1] + squares[i][2];
        }
        while (low <= high) {
            mid = low + (low + high) / 2;
            double low_area = 0, high_area = 0;
            for (int i=0; i<squares.size(); i++) {
                double area = squares[i][2] * squares[i][2];
                if (squares[i][1] + squares[i][2] <= mid) low_area += area;
                else if (squares[i][1] >= mid) high_area += area;
                else {
                    low_area += (mid - squares[i][1]) * area;
                    high_area += (squares[i][1] - mid) * area;
                }
            }
            cout <<"low_area = "<<low_area<<" high_area = "<<high_area<<"\n";
            if (low_area - high_area <= 1e-6) break;
            if (high_area > low_area) low = mid;
            if (high_area < low_area) high = mid;
        }
        return mid;
    }
};