/*************************************************************************
    > File Name:  suggestedProducts.cpp
    > Author: shenming
    > Created Time: Mon Dec  2 23:33:09 2019
************************************************************************/

#include "lc_common.h"

class Solution {
public:

    void subProducts(vector<string>& products, int depth, int start, int end,
                     string& searchWord, vector<vector<string>>& res) {
        if (depth >= searchWord.size()) {
            return;
        }
        char c = searchWord[depth];
        vector<string> cur;
        int new_start = -1;
        int new_end = -1;
        for (int i = start; i < end && i < products.size(); i++) {
            std::string product = products[i];
            char pc = product[depth];
            if (pc == c) {
                if (new_start < 0) {
                    new_start = i;
                }
                if (cur.size() < 3) {
                    cur.push_back(product);
                }
                new_end = i+1;
            }
        }
        res.push_back(cur);
        subProducts(products, depth+1, new_start, new_end, searchWord, res);
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::sort(products.begin(), products.end());
        vector<vector<string>> res;
        subProducts(products, 0, 0, products.size(), searchWord, res);
        return res;
    }
};

// cool
// lower_bound: return the first element in the range [first, last) that is not less than (i.e. greater or equal to) value
class Solution_ref {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        for (int l = 0; l < searchWord.size(); ++ l) {
            auto start = lower_bound(products.begin(), products.end(), searchWord.substr(0, l+1));
            auto end = lower_bound(start, min(start+3, products.end()), searchWord.substr(0, l) + (char)(searchWord[l]+1));
            result.push_back(vector<string>(start, end));
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    // vector<string> products = {"hello", "world", "abc", "wad"};
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    std::string searchWord = "mouse";
    Solution s;
    vector<vector<string>> vv = s.suggestedProducts(products, searchWord);
    for (auto i = vv.begin(); i != vv.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            printf("%s\t", j->c_str());
        }
        printf("\n");
    }
}
