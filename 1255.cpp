#include<bits/stdc++.h>
using namespace std;

// 爆搜牛逼
class Solution {
public:
    unordered_map<char, int>& add_back_cnt(unordered_map<char, int>& letter_cnt, string word) {
        for (int i=0; i<word.size(); i++) {
            letter_cnt[word[i]]++;
        }
        return letter_cnt;
    }
    unordered_map<char, int>& remove_cnt(unordered_map<char, int>& letter_cnt, string word) {
        for (int i=0; i<word.size(); i++) {
            letter_cnt[word[i]]--;
        }
        return letter_cnt;
    }
    bool is_valid(unordered_map<char, int> letter_cnt, string word) {
        for (int i=0; i<word.size(); i++) {
            if (letter_cnt[word[i]] > 0) letter_cnt[word[i]]--;
            else return false;
        }
        return true;
    }
    int calculate_score(vector<int>& score, string& word) {
        int total_score = 0;
        for (char c : word) {
            total_score += score[c - 'a'];
        }
        return total_score;
    }
    void dfs(vector<string>& words, unordered_map<char, int> letter_cnt, vector<int>& word_score, int level) {
        if (level >= words.size()) {
            ans = max(ans, now_score);
            return;
        }
        // 取
        int flag = 0;
        if (is_valid(letter_cnt, words[level])) {
            flag = 1;
            now_score += word_score[level];
            remove_cnt(letter_cnt, words[level]);
        }
        dfs(words, letter_cnt, word_score, level+1);
        // 不取
        if (flag) {
            now_score -= word_score[level];
            add_back_cnt(letter_cnt, words[level]);
            dfs(words, letter_cnt, word_score, level+1);
        }
    }
    int ans = 0, now_score = 0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letter_cnt;
        for (int i=0; i<letters.size(); i++) {
            letter_cnt[letters[i]]++;
        }
        vector<int> word_score(words.size(), 0);
        for (int i=0; i<words.size(); i++) {
            if (is_valid(letter_cnt, words[i])) word_score[i] = calculate_score(score, words[i]);
        }
        dfs(words, letter_cnt, word_score, 0);
        return ans;
    }
};