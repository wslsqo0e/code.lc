/*************************************************************************
> File Name:  print-binary-tree.cpp
> Author: shenming
> Created Time: Tue Feb 18 20:41:27 2020
************************************************************************/

#include "common_lc.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void expand(vector<vector<string>>& tree, int height)
    {
        int width = pow(2, height) - 1;
        for (int i = tree.size(); i < height; i++) {
            vector<string> vv(width, "");
            tree.push_back(vv);
        }
        for (auto &t : tree) {
            if (t.size() < width) {
                int len = (width - t.size())/2;
                vector<string> vv(len, "");
                t.insert(t.begin(), vv.begin(), vv.end());
                t.insert(t.end(), vv.begin(), vv.end());
            }
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ret;
        if (root == NULL) {
            return ret;
        }
        string cur = to_string(root->val);
        vector<vector<string>> r_left = printTree(root->left);
        vector<vector<string>> r_right = printTree(root->right);
        if (r_left.size() > r_right.size()) {
            expand(r_right, r_left.size());
        } else if (r_right.size() > r_left.size()) {
            expand(r_left, r_right.size());
        }
        ret.push_back({cur});
        int height = r_left.size();
        if (height == 0) {
            return ret;
        }
        vector<string> vv(r_left[0].size(), "");
        ret[0].insert(ret[0].begin(), vv.begin(), vv.end());
        ret[0].insert(ret[0].end(), vv.begin(), vv.end());
        for (int i = 0; i < height; i++) {
            vector<string> t;
            t.push_back("");
            t.insert(t.begin(), r_left[i].begin(), r_left[i].end());
            // printf("%d\n", t.size());
            t.insert(t.end(), r_right[i].begin(), r_right[i].end());
            // printf("%d\n", t.size());
            ret.push_back(t);
            // printf("%d\n", t.size());
        }
        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode* l = new TreeNode(2);
    TreeNode* root = new TreeNode(1);
    root->left = l;
    s.printTree(root);
    return 0;
}
