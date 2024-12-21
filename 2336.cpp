#include<bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
    set<int> S;
    SmallestInfiniteSet() {
        for (int i=1; i<=1001; i++) {
            S.insert(i);
        }
    }
    
    int popSmallest() {
        int ret = *S.begin();
        S.erase(S.begin());
        return ret;
    }
    
    void addBack(int num) {
        S.insert(num);
    }
};

class SmallestInfiniteSet {
public:
    set<int> S;
    int cnt = 1;
    SmallestInfiniteSet() {
        S.insert(1);
    }
    
    int popSmallest() {
        cnt++;
        int ret = *S.begin();
        S.erase(S.begin());
        if (S.empty()) S.insert(cnt);
        return ret;
    }
    
    void addBack(int num) {
        S.insert(num);
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */