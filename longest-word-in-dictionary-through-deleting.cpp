/*************************************************************************
> File Name:  longest-word-in-dictionary-through-deleting.cpp
> Author: shenming
> Created Time: Thu Feb 13 15:35:06 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        queue<pair<int, string>> qs;
        sort(d.begin(), d.end());
        int N = d.size();
        for (int i = 0; i < N; i++) {
            qs.push({0, d[i]});
        }
        int max_len = 0;
        int len = qs.size();
        int count = 0;
        string str;
        while (!qs.empty()) {
            pair<int, string> cur = qs.front(); qs.pop();
            // printf("%d %d %s\n", count, cur.first, cur.second.c_str());
            len--;
            if (count == (int)cur.second.size()) {
                if (count > max_len) {
                    max_len = count;
                    str = cur.second;
                }
            } else {
                size_t pos = s.find(cur.second[count], cur.first);
                if (pos == string::npos) {
                } else {
                    cur.first = pos + 1;
                    qs.push(cur);
                }
            }
            if (len == 0) {
                len = qs.size();
                count++;
            }
        }

        return str;
    }
};

int main()
{
    Solution s;
    vector<string> d = {"ale","apple","monkey","plea"};
    string ss = s.findLongestWord("abpcplea", d);
    trace(ss);
    return 0;
}
