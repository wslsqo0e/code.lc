/*************************************************************************
> File Name:  Decode_string_at_index.cpp
> Author: shenming
> Created Time: Fri Jan 31 00:25:54 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        vector<long long> vl;
        vector<string> vs;

        long long c_l = 0;
        string s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] >= '2' && S[i] <= '9') {
                if (s.empty()) {
                    c_l *= (S[i] - '0');
                    s = vs[vs.size() - 1];
                } else {
                    c_l *= (S[i] - '0');
                    vl.push_back(c_l);
                    vs.push_back(s);
                }
                if (c_l == K) {
                    // return s[s.size() - 1];
                    cout << s.size() - 1 << endl;
                    cout << "H" << endl;
                    return s.substr(s.size() - 1, 1);
                }
                s = "";
            }
            else {
                c_l++;
                s += S[i];
            }
            if (c_l >= K) {
                if (c_l == K) {
                    cout << i << endl;;
                    return S.substr(i, 1);
                }
                break;
            }
        }
        print_vec<long long> (vl);
        print_vec<string> (vs);
        for (int i = vl.size() - 1; i >= 1; i--) {
            printf("K %d %d\n", K, vl[i]);
            K %= vl[i];
            if (K <= vl[i-1] + vs[i].size() && K > vl[i-1]) {
                // return vs[i][K - vl[i-1]-1];
                cout << K - vl[i-1]-1 << endl;
                cout << "H" << endl;
                return vs[i].substr(K - vl[i-1]-1, 1);
            }
        }
        // return vs[0][K%vl[0]-1];
        cout << K << endl;
        cout << K%vl[0]-1 << endl;
        cout << "H" << endl;
        if (K % vl[0] == 0) {
            return vs[0].substr(vs[0].size(), 1);
        }
        return vs[0].substr(K%vl[0]-1, 1);
    }
};

int main()
{
    Solution s;
    // string ret = s.decodeAtIndex("aw4eguc6cs", 41);
    string ret = s.decodeAtIndex("ha22", 4);
    cout << ret << endl;;
    return 0;
}
