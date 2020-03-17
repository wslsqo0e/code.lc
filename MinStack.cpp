/*************************************************************************
> File Name:  MinStack.cpp
> Author: shenming
> Created Time: Sun Jan 26 18:04:13 2020
************************************************************************/

#include "common_lc.h"
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;

    MinStack() {
    }

    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            s2.push(x);
        } else {
            if (x <= s2.top()) {
                s2.push(x);
            }
            s1.push(x);
        }
    }

    void pop() {
        if (s1.top() == s2.top()) {
            s1.pop();
            s2.pop();
        } else {
            s1.pop();
        }
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
}

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        multiset<int> ss;
        stack<int> sta;
    }

    void push(int x) {
        sta.push(x);
        ss.insert(x);
    }

    void pop() {
        int x = sta.top();
        sta.pop();
        auto s = ss.find(x);
        ss.erase(s);
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        auto s= ss.begin();
        return *s;
    }
};
