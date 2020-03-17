/*************************************************************************
> File Name:  Distinct_Echo_Substring.cpp
> Author: shenming
> Created Time: Tue Jan 28 14:51:40 2020
************************************************************************/

#include "common_lc.h"

// https://leetcode.com/problems/distinct-echo-substrings/discuss/488360/Easy-to-understand-c%2B%2B-solution-using-hash
class Solution_ref {
public:
    typedef long long ll;
    const ll A = 1000000007, B = 998244353;
    ll h[2001], base[2001];
    void hash(string s) {
        h[0] = s[0] % B;
        base[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            h[i] = (h[i-1]*A + s[i]) % B;
            base[i] = (base[i - 1] * A) % B;
        }
    }
    ll getHashValue(int l, int r) {
        if (l == 0) {
            return h[r];
        }
        ll ans = (h[r] - l[l-1] * base[r - (l-1)]) %B;
        if (ans < 0) {
            return B + ans;
        }
        else {
            return ans;
        }
    }
    int distinctEchoSubstrings(string text) {
        hash(text);
        unordered_set<string> se;
        for(int i = 0; i < text.size(); i++) {
            for(int len = 1; i + len + len <= text.size(); len++){
                if(getHashValue(i, i + len - 1) == getHashValue(i + len, i + len + len -1)) {
                    se.insert(text.substr(i, len));
                }
            }
        }
        return se.size();
    }
};

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        vector<int> jump(text.size(), -1);
        std::map<char, int> mmm;
        for (int i = text.size() - 1; i >= 0; i--) {
            char c = text[i];
            if (mmm.count(c)) {
                jump[i] = mmm[c];
            }
            mmm[c] = i;
        }

        set<string> ss;
        for (int i = 0; i < text.size()-1; i++) {
            int k = jump[i];
            while (k != -1) {
                if (2*k - i <= text.size()) {
                    string s1 = text.substr(i, k-i);
                    string s2 = text.substr(k, k-i);
                    if (s1 == s2) {
                        ss.insert(s1);
                    }
                }
                k = jump[k];
            }
        }
        return ss.size();
    }
};

int main()
{
    Solution s;
    // int ret = s.distinctEchoSubstrings("abcabcabc");
    int ret = s.distinctEchoSubstrings("leetcodeleetcode");
    trace(ret);
    return 0;
}
