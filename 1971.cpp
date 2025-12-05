#include<bits/stdc++.h>
using namespace std;

// TLE QQ
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> Q;
        vector<bool> visit(n, false);
        Q.push(source);
        visit[source] = true;
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (int i=0; i<edges.size(); i++) {
                if (edges[i][0] == now && !visit[edges[i][1]]) {
                    Q.push(edges[i][1]);
                    visit[edges[i][1]] = true;
                }
                if (edges[i][1] == now && !visit[edges[i][0]]) {
                    Q.push(edges[i][0]);
                    visit[edges[i][0]] = true;
                }
            }
            if (visit[destination]) return true;
        }
        return false;
    }
};

// 用adjacent list 過了!
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> Q;
        vector<bool> visit(n, false);
        vector<vector<int>> adjacent_list(n);
        for (int i=0; i<edges.size(); i++) {
            adjacent_list[edges[i][0]].push_back(edges[i][1]);
            adjacent_list[edges[i][1]].push_back(edges[i][0]);
        }
        Q.push(source);
        visit[source] = true;
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (int i=0; i<adjacent_list[now].size(); i++) {
                if (!visit[adjacent_list[now][i]]) {
                    Q.push(adjacent_list[now][i]);
                    visit[adjacent_list[now][i]] = true;
                }
            }
            if (visit[destination]) return true;
        }
        return false;
    }
};