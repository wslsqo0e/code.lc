/*************************************************************************
> File Name:  Basic_calculator.cpp
> Author: shenming
> Created Time: Wed Jan 29 13:03:55 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    string min_cal(string s) {
        cout << s << endl;
        char pre_c = ' ';
        string pre;
        string suf;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (!pre.size()) {
                    pre = s[i];
                    continue;
                }
                pre_c = s[i];
                string ns = s.substr(i + 1);
                printf("ns %s\n", ns.c_str());
                if (pre_c == '-') {
                    int ii = 0;
                    while (ns[ii] == '+' || ns[ii] == '-') {
                        ii++;
                    }
                    for (; ii < ns.size(); ii++) {
                        if (ns[ii] == '-') {
                            ns[ii] = '+';
                            continue;
                        }
                        if (ns[ii] == '+') {
                            ns[ii] = '-';
                            continue;
                        }
                    }
                }
                printf("ns %s\n", ns.c_str());
                suf = min_cal(ns);
                break;
            }
            if ((s[i] != '+' && s[i] != '-')) {
                pre += s[i];
            }
        }
        if (pre_c == ' ') {
            return s;
        }
        if (pre.size() == 0) {
            pre = "0";
        }
        int ret;
        switch(pre_c) {
            case '+':
                ret = stoi(pre) + stoi(suf);
                break;
            case '-':
                ret = stoi(pre) - stoi(suf);
                break;
        }
        cout << "pre " << pre << " suf " << suf << " ret " << ret << endl;
        return to_string(ret);
    }

    int calculate(string s) {
        stack<char> sc;
        for (auto i : s) {
            if (i == ' ') {
                continue;
            }
            if (i != ')') {
                sc.push(i);
            } else {
                string ss;
                while (sc.top() != '(') {
                    ss += sc.top();
                    sc.pop();
                }
                sc.pop();
                reverse(ss.begin(), ss.end());
                ss = min_cal(ss);
                while ((ss[0] == '-' || ss[0] == '+')&& !sc.empty() && (sc.top() == '-' || sc.top() == '+')) {
                    char c = sc.top();
                    sc.pop();
                    if (c == '-') {
                        ss[0] = ss[0] == '+' ? '-' : '+';
                    }
                }
                for (auto k : ss) {
                    sc.push(k);
                }
            }
        }
        string ss;
        while (!sc.empty()) {
            ss += sc.top();
            sc.pop();
        }
        reverse(ss.begin(), ss.end());
        ss = min_cal(ss);
        return stoi(ss);
    }
};

int main()
{
    Solution s;
    // string ss = " 2 - ( 5 - 6)";
    // string ss = "(1+(4+5+2)-18)+(6+8)";
    // string ss = "2-4-(8+2-6+(8+4-(1)+8-10))";
    string ss = "1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10";
    int ret = s.calculate(ss);
    trace(ret);
    return 0;
}
