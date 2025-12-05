#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long C(long long a, long long b) {
        if (b == 0) return 1;
        if (b == 1) return a;
        long long tmp = b <= a/2 ? b : a-b;
        long long tmp_a = tmp, tmp_b = tmp;
        long long ans = 1, b_now = 1;
        // C(10, 3) 10 * 9 * 8 / 1 * 2 * 3
        while (tmp_a--) {
            ans *= a--;
            ans /= b_now++;
        }
        return ans;
    }
    long long combination(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r; // C(n, r) = C(n, n-r)
        long long result = 1;
        for (int i = 1; i <= r; i++) {
            result = (result * (n - i + 1)) % mod; // 避免溢出
            result = result / i;
        }
        return result % mod;
    }
    long long mod = 1e9+7;
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long len = nums.size();
        long long ans = 0;
        while(k > 1) {
            for (long long end = len-1; end >= k-1; end--) {
                long long last_begin = end - k + 1;
                for (long long i=0; i<=last_begin; i++) {
                    long long val = (nums[i] + nums[end]) % mod;
                    long long comb = combination(end - i - 1, k-2);
                    ans = (ans + (val * comb) % mod) % mod;
                }
            }
            k--;
        }
        for (long long i=0; i<len; i++) {
            ans = (ans + 2*nums[i]) % mod;
        }
        return ans % mod;
    }
};
/*
[1,2,3,4,5], k = 4

*/