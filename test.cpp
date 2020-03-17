#include "common_lc.h"
// #include <bits/stdc++.h>

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int LEN;
    vector<vector<pair<int, int>>> cont;
    MyHashMap() {
        LEN = 8096;
        cont.resize(LEN);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key%LEN;
        vector<pair<int, int>>& vv = cont[hash];
        auto iter = vv.begin();
        while (iter != vv.end()) {
            if (iter->first == key) {
                iter->second = value;
                return;
            } else if (iter->first > key) {
                vv.insert(iter, {key, value});
                return;
            }
        }
        vv.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key%LEN;
        vector<pair<int, int>>& vv = cont[hash];
        auto iter = vv.begin();
        while (iter != vv.end()) {
            if (iter->first == key) {
                return iter->second;
            }
            if (iter->first > key) {
                break;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key%LEN;
        vector<pair<int, int>>& vv = cont[hash];
        auto iter = vv.begin();
        while (iter != vv.end()) {
            if (iter->first == key) {
                vv.erase(iter);
                break;
            }
            if (iter->first > key) {
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
