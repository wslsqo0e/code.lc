/*************************************************************************
> File Name:  online-majority-element-in-subarray.cpp
> Author: shenming
> Created Time: Sun Feb 16 11:40:44 2020
************************************************************************/

#include "common_lc.h"

class MajorityChecker_random_pick {
public:
    unordered_map<int, vector<int>> pos;
    vector<int> a;
    int try_bound;

    MajorityChecker_random_pick(vector<int>& arr) {
        srand(time(nullptr));
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
        }
        try_bound = 20;
    }

    int get_occurrence(int num, int l, int r) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }

    int get_random(int l, int r) {
        return rand() % (r - l + 1) + l;
    }

    int query(int left, int right, int threshold) {
        for (int i = 0; i < try_bound; ++i) {
            int elem = a[get_random(left, right)];
            if (get_occurrence(elem, left, right) >= threshold) {
                return elem;
            }
        }
        return -1;
    }
};

class MajorityChecker_trade_off {
public:
    unordered_map<int, vector<int>> pos;
    unordered_set<int> popular;
    vector<int> a;
    int lookup_bound;

    MajorityChecker(vector<int>& arr): a(arr) {
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
        }
        lookup_bound = round(sqrt(arr.size()));
        for (const auto& [key, value]: pos) {
            if (value.size() >= lookup_bound) {
                popular.insert(key);
            }
        }
    }

    int get_occurrence(int num, int l, int r) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }

    int vote(int l, int r) {
        int target = a[l], occ = 1;
        for (int i = l + 1; i <= r; ++i) {
            if (a[i] == target) {
                ++occ;
            }
            else {
                --occ;
                if (occ < 0) {
                    target = a[i];
                    occ = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i] == target) {
                ++cnt;
            }
        }
        if (cnt * 2 > r - l + 1) {
            return target;
        }
        return -1;
    }

    int query(int left, int right, int threshold) {
        if (threshold <= lookup_bound) {
            int candidate = vote(left, right);
            if (candidate != -1 && get_occurrence(candidate, left, right) >= threshold) {
                return candidate;
            }
            return -1;
        }
        else {
            for (const int& elem: popular) {
                if (get_occurrence(elem, left, right) >= threshold) {
                    return elem;
                }
            }
            return -1;
        }
    }

};

class MajorityChecker_segment_tree {
public:
    unordered_map<int, vector<int>> pos;
    vector<int> tree;
    vector<int> a;

    MajorityChecker_segment_tree(vector<int>& arr): a(arr) {
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
        }
        tree = vector<int>(arr.size() * 4, -1);
        build_tree(1, 0, arr.size() - 1);
    }

    void build_tree(int tree_pos, int l, int r) {
        if (l == r) {
            tree[tree_pos] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build_tree(tree_pos * 2, l, mid);
        build_tree(tree_pos * 2 + 1, mid + 1, r);
        if (tree[tree_pos * 2] != -1 && get_occurrence(tree[tree_pos * 2], l, r) * 2 > r - l + 1) {
            tree[tree_pos] = tree[tree_pos * 2];
        }
        else if (tree[tree_pos * 2 + 1] != -1 && get_occurrence(tree[tree_pos * 2 + 1], l, r) * 2 > r - l + 1) {
            tree[tree_pos] = tree[tree_pos * 2 + 1];
        }
    }

    pair<int, int> query(int tree_pos, int l, int r, int queryl, int queryr) {
        if (l > queryr || r < queryl) {
            return make_pair(-1, -1);
        }
        if (queryl <= l && r <= queryr) {
            if (tree[tree_pos] == -1) {
                return make_pair(-1, -1);
            }
            int occ = get_occurrence(tree[tree_pos], queryl, queryr);
            if (occ * 2 > queryr - queryl + 1) {
                return make_pair(tree[tree_pos], occ);
            }
            else {
                return make_pair(-1, -1);
            }
        }
        int mid = (l + r) >> 1;
        pair<int, int> res_l = query(tree_pos * 2, l, mid, queryl, queryr);
        if (res_l.first > -1) {
            return res_l;
        }
        pair<int, int> res_r = query(tree_pos * 2 + 1, mid + 1, r, queryl, queryr);
        if (res_r.first > -1) {
            return res_r;
        }
        return make_pair(-1, -1);
    }

    int get_occurrence(int num, int l, int r) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }

};

int main()
{
    Solution s;

    return 0;
}
