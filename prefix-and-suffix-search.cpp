/*************************************************************************
> File Name:  prefix-and-suffix-search.cpp
> Author: shenming
> Created Time: Sat Feb 15 21:19:26 2020
************************************************************************/

#include "common_lc.h"

class WordFilter {
public:
    struct Trie {
        vector<int> vv;
        map<char, Trie> next;
    };

    Trie prefix_trie;
    Trie suffix_trie;
    vector<string> m_words;

    WordFilter(vector<string>& words) {
        m_words = words;
        for (int i = 0; i < words.size(); i++) {
            add_pre_word(words[i], i);
            add_suf_word(words[i], i);
        }
    }

    int f(string prefix, string suffix) {
        vector<int> vv1;
        vector<int> vv2;
        int rr = search_pre_word(prefix, vv1);
        if (rr != 0) {
            return -1;
        }
        rr = search_suf_word(suffix, vv2);
        if (rr != 0) {
            return -1;
        }

        int i = vv1.size() - 1;
        int j = vv2.size() - 1;
        while (i>=0 && i>=0) {
            if (vv1[i] == vv2[j]) {
                return vv1[i];
            }
            if (vv1[i] > vv2[j]) {
                i--;
                continue;
            }
            if (vv1[i] < vv2[j]) {
                j--;
                continue;
            }
        }
        return -1;
    }

    int search_pre_word(string prefix, vector<int>& ret) {
        Trie* cur = &prefix_trie;
        int count = 0;
        while (count < (int)prefix.size()) {
            char k = prefix[count++];
            if (!cur->next.count(k)) {
                return -1;
            }
            cur = &(cur->next[k]);
        }
        ret = cur->vv;
        return 0;
    }

    int search_suf_word(string suffix, vector<int>& ret) {
        Trie* cur = &suffix_trie;
        int count = 0;
        while (count < (int)suffix.size()) {
            char k = suffix[suffix.size() - count - 1];
            count++;
            if (!cur->next.count(k)) {
                return -1;
            }
            cur = &(cur->next[k]);
        }
        ret  = cur->vv;
        return 0;
    }

    void add_pre_word(string& word, int index) {
        Trie* cur = &prefix_trie;
        int count = 0;
        while (count < (int)word.size()) {
            cur->vv.push_back(index);
            char k = word[count++];
            cur = &(cur->next[k]);
        }
        if (count > 0) {
            cur->vv.push_back(index);
        }
    }


    void add_suf_word(string& word, int index) {
        // printf("call add suf word\n");
        Trie* cur = &suffix_trie;
        int count = 0;
        while (count < (int)word.size()) {
            cur->vv.push_back(index);
            // printf("suf add %d %p\n", index, cur);
            char k = word[word.size() - count - 1];
            count++;
            cur = &(cur->next[k]);
        }
        if (count > 0) {
            cur->vv.push_back(index);
        }
    }
};

int main()
{
    // Solution s;
    vector<string> words = {"apple"};
    WordFilter* obj = new WordFilter(words);
    int param_1 = obj->f("a","e");
    trace(param_1);
    return 0;
}
