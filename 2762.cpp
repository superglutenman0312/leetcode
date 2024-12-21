#include<bits/stdc++.h>
using namespace std;

// 暴力解(N^3) TLE QQ
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int cnt = 0;
        for (int size=1; size<=nums.size(); size++) {
            for (int i=0; i<nums.size(); i++) {
                if (i+size > nums.size()) break;
                int maxx = nums[i], minn = nums[i];
                for (int j=i; j<i+size; j++) {
                    maxx = max(nums[j], maxx);
                    minn = min(nums[j], minn);
                }
                if (maxx - minn <= 2) cnt++;
            }
        }
        return cnt;
    }
};


// GPT的，看不懂
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long int cnt = 0;
        long long int start = 0;
        multiset<long long int> window;
        for (long long int end=0; end<nums.size(); end++) {
            window.insert(nums[end]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[start]));
                start++;
            }
            cnt += (end - start + 1);
        }
        return cnt;
    }
};
/*
5 (+1)
5 4 (+2)
2 4 (+2)
2 4 4 (+3)
*/
