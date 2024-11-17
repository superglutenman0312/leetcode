#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> Q1;
    queue<int> Q2;
    MyStack() {
        
    }
    
    void push(int x) {
        Q1.push(x);
    }
    
    int pop() {
        while (Q1.size() > 1) {
            Q2.push(Q1.front());
            Q1.pop();
        }
        int ans = Q1.front();
        Q1.pop();
        swap(Q1,Q2);
        return ans;
    }
    
    int top() {
        while (Q1.size() > 1) {
            Q2.push(Q1.front());
            Q1.pop();
        }
        int ans = Q1.front();
        Q2.push(Q1.front());
        Q1.pop();
        swap(Q1,Q2);
        return ans;
    }
    
    bool empty() {
        return Q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */