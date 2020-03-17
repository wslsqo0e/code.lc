/*************************************************************************
> File Name:  frog-position-after-t-seconds.cpp
> Author: shenming
> Created Time: Fri Mar 13 20:38:15 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int T;
    int Target;
    double Prob;
    vector<double> prob_vec;
    void get_prob(int t, double p, int v, set<int>& ss, unordered_map<int, vector<int>>& tree)
    {
        printf("Target %d T %d\n", Target, T);
        ss.insert(v);
        if (t == T) {
            if (v == Target) {
                Prob += p;
            }
            ss.erase(v);
            return;
        }

        if (t > T) {
            ss.erase(v);
            return;
        }

        vector<int>& next_v = tree[v];
        vector<int> next_avaiable;
        for (auto n : next_v) {
            if (ss.count(n)) {
                continue;
            }
            next_avaiable.push_back(n);
        }
        if (next_avaiable.size() == 0) {
            if (v == Target) {
                Prob += p;
            }
            ss.erase(v);
            return;
        }
        p = p/next_avaiable.size();
        for (auto n : next_avaiable) {
            printf("trying %d %d %f\n", t+1, n, p);
            get_prob(t+1, p, n, ss, tree);
        }
        ss.erase(v);
        return;
    }


    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        T = t;
        Target = target;
        Prob = 0;
        prob_vec.resize(n+1);
        unordered_map<int, vector<int>> tree;
        for (auto& v : edges) {
            tree[v[0]].push_back(v[1]);
            tree[v[1]].push_back(v[0]);
        }
        set<int> ss;
        get_prob(0, 1., 1, ss, tree);

        return Prob;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    double ret = s.frogPosition(7, edges, 2, 4);
    trace(ret);
    return 0;
}
