/*************************************************************************
> File Name:  maximum-frequency-stack.cpp
> Author: shenming
> Created Time: Tue Feb 18 14:49:25 2020
************************************************************************/
#include "common_lc.h"
class FreqStack {
public:
    map<pair<unsigned int, int>, int> mp;
    unordered_map<int, int> cc;
    int index;
    FreqStack() {
        index = 0;
    }

    void push(int x) {
        cc[x]++;
        index++;
        mp[{cc[x], index}] = x;
    }

    int pop() {
        auto i = mp.rbegin();
        // printf("%d %d %d\n", i->first.first, i->first.second, i->second);
        int ret = i->second;
        mp.erase(mp.find(i->first));
        // printf("%d\n", ret);
        cc[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main()
{
    FreqStack obj;
    obj.push(4);
    obj.push(0);
    obj.push(9);
    obj.push(3);
    obj.push(4);
    obj.push(2);
    obj.pop();
    obj.push(6);
    obj.pop();
    obj.push(1);
    obj.pop();
    obj.push(1);
    obj.pop();
    obj.push(4);
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    return 0;
}
