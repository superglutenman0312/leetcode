#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9+7;
        vector<int> arr1(n, 1);
        vector<int> arr2(n, 1);
        while (k--) {
            int prefix_sum = 1;
            for (int i=1; i<arr1.size(); i++) {    
                arr2[i] = (prefix_sum + arr1[i]) % mod;
                prefix_sum = arr2[i];
            }
            arr1 = arr2;
        }
        return arr1[n-1];
    }
};

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9+7;
        vector<int> arr(n, 1);
        while (k--) {
            for (int i=1; i<arr.size(); i++) {    
                arr[i] = (arr[i-1] + arr[i]) % mod;
            }
        }
        return arr[n-1];
    }
};

class Solution {
public:
    int mod = 1e9+7;
    long long int comb(int a, int b) {
        if (b > a/2) b = a - b;
        long long int num = 1, tmp = 1;
        for (int i=a; i>(a-b); i--){
            num *= (i % mod);
            num /= (tmp % mod);
            num %= mod;
            cout << "i = "<<i<<", tmp = "<<tmp<<", num = "<<num<<"\n";
            tmp++;
        }
        return num;
    }
    int valueAfterKSeconds(int n, int k) {
        return comb(n-1+k, k);
    }
};

/*
C6取2 = 6*5/2*1
6!/4!2!
C(n - 1 + k, k)
*/
class Solution {
public:
    int mod = 1e9+7;
    long long int comb(int a, int b) {
        long long int ll1 = 1;
        long long int ll2 = 1;        
        long long int ll3 = 1; 
        for (int i=1; i<=a; i++) {
            ll1 *= i;
            ll1 %= mod;
        }
        for (int i=1; i<=b; i++) {
            ll2 *= i;
            ll2 %= mod;
        }
        for (int i=1; i<=(a-b); i++) {
            ll3 *= i;
            ll3 %= mod;
        }
        cout << ll1 <<" "<<ll2<<" "<<ll3 <<"\n";
        return (ll1 / (ll2*ll3)) % mod;
    }
    int valueAfterKSeconds(int n, int k) {
        return comb(n-1+k, k);
    }
};