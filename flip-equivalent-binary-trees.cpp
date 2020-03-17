/*************************************************************************
> File Name:  flip-equivalent-binary-trees.cpp
> Author: shenming
> Created Time: Tue Feb 18 14:14:34 2020
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1->val != root2->val) {
            return false;
        }
        if (root1->left == NULL && root2->right == NULL &&
            root2->left == NULL && root2->right == NULL) {
            return true;
        }
        if (root1->left != NULL && root2->right != NULL &&
            root2->left != NULL && root2->right != NULL) {
            if (root1->left->val == root2->left->val &&
                root1->right->val == root2->right->val) {
                return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
            }
            if (root1->left->val == root2->right->val &&
                root1->right->val == root2->left->val) {
                return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            }
            return false;
        } else {
            if (root1->right == NULL) {
                swap(root1->left, root1->right);
            }
            if (root2->right == NULL) {
                swap(root2->left, root2->right);
            }

            if (root1->left == NULL && root2->left == NULL && root1->right && root2->right) {
                return flipEquiv(root1->right, root2->right);
            }
            return false;
        }
        return false;
    }
};

int main()
{
    Solution s;

    return 0;
}
