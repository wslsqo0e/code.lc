/*************************************************************************
> File Name:  Substring_with_Concatenation_of_All_Words.cpp
> Author: shenming
> Created Time: Sat Feb  1 19:07:35 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:

    bool check(vector<int>& s_id, int idx, vector<pair<string, int>> vs, int word_len) {
        int len = vs.size();
        int c = 0;
        while (s_id[idx] != -1) {
            int ii = s_id[idx];
            vs[ii].second--;
            if (vs[ii].second == 0) {
                c++;
            } else if(vs[ii].second < 0) {
                break;
            }
            if (c == len) {
                return true;
            }
            if (idx+word_len >= s_id.size()) {
                break;
            }
            idx = idx+word_len;
        }
        return false;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words.size();
        if (len == 0) {
            return vector<int>();
        }
        int word_len = words[0].size();
        map<string, int> mm;
        vector<pair<string, int>> vs;
        vector<int> s_id(s.size(), -1);

        for (auto word : words) {
            if (!mm.count(word)) {
                mm[word] = 1;
            } else {
                mm[word]++;
            }
        }
        for (auto wc : mm) {
            vs.push_back(wc);
        }

        for (int i = 0; i < vs.size(); i++) {
            string word = vs[i].first;
            int start = s.find(word);
            while (start != string::npos) {
                s_id[start] = i;
                start = s.find(word, start+1);
            }
        }
        vector<int> ret;
        for (int i = 0; i < s.size(); i++) {
            if (check(s_id, i, vs, word_len)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string ss = "";
    vector<string> vs = {"good", "good", "best", "word"};
    vector<int> ret = s.findSubstring(ss, vs);
    print_vec<int>(ret);
    return 0;
}
