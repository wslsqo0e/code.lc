/*************************************************************************
> File Name:  maximum-level-sum-of-a-binary-tree.cpp
> Author: shenming
> Created Time: Mon Feb  3 18:18:16 2020
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
    int maxLevelSum(TreeNode* root) {
        int max_sum = 0;
        int max_level = -1;
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while (!que.empty()) {
            level++;
            int N = que.size();
            int sum = 0;
            while (N--) {
                TreeNode* cur = que.front();
                que.pop();
                sum += cur->value;
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
            if (sum > max_sum) {
                max_level = level;
                max_sum = sum;
            }
        }
        return max_level;
    }
};

int main()
{
    Solution s;

    return 0;
}
