/*************************************************************************
> File Name:  common_lc.h
> Author: shenming
> Created Time: Sat Jan 25 08:51:21 2020
************************************************************************/


// #pragma GCC diagnostic error "-std=c++11"
#include <stdio.h>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <queue>
#include <numeric>
#include <bitset>
#include <sstream>
using namespace std;

typedef long long ll;
typedef long double ld;
// #define pb push_back
// #define el endl;cout.flush()
// #define be begin()
// #define fi first
// #define se second
// #define br break
// #define en end()
// #define vl vector<ll>
// #define pll vector<pair<ll,ll> >
// #define vll vector<pair<ll,ll> >
#define trace(a) cout << "a is " << a << endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// INT_MAX means NULL
TreeNode* init_tree_node(std::vector<int> vv) {
    TreeNode* root = NULL;
    if (vv.size()) {
        root = new TreeNode(vv[0]);
    } else {
        return root;
    }

    int count = 1;
    queue<TreeNode*> qq;
    qq.push(root);
    while (count < vv.size()) {
        TreeNode* cur = qq.front();
        qq.pop();
        if (vv[count] != INT_MAX) {
            cur->left = new TreeNode(vv[count]);
            qq.push(cur->left);
        }
        count++;
        if (vv[count] != INT_MAX) {
            cur->right = new TreeNode(vv[count]);
            qq.push(cur->right);
        }
        count++;
    }
    return root;
}

template<class T>
void print_vec(vector<T>& vv) {
    for (auto v: vv) {
        cout << v << " ";
    }
    cout << endl;
}

template<class T>
void print_vv(vector<vector<T>>& vv) {
    for (auto v : vv) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "|| ";
    }
    cout << endl;
}
