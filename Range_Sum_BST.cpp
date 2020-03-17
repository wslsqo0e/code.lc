/*************************************************************************
> File Name:  Range_Sum_BST.cpp
> Author: shenming
> Created Time: Sun Jan 26 17:14:18 2020
************************************************************************/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        queue<TreeNode*> que;
        if (root) {
            que.push(root);
        }
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur->val >= L && cur->val <= R) {
                sum += cur->val;
            }
            if (cur->left && cur->val > L ) {
                que.push(cur->left);
            }
            if (cur->right && cur->val < R) {
                que.push(cur->right);
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;

    return 0;
}
