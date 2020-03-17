/*************************************************************************
> File Name:  Max_width_of_Binary_Tree.cpp
> Author: shenming
> Created Time: Mon Jan 27 22:00:10 2020
************************************************************************/

#include "common_lc.h"

class Solution_ref {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        if (root == NULL) {
            return result;
        }

        deque<pair<TreeNode*, int>> dq;
        dq.push_back(make_pair(root, 0));
        while(!dq.empty()) {
            int cureSzie = dq.size();
            pair<TreeNode*, int> f= dq.front();
            pair<TreeNode*, int> b= dq.back();
            result = max(result,((b.second-f.second)+1));
            for (int i = 0; i < curSize; i++) {
                pair<TreeNode*,int> fp = dq.front();
                TreeNode* node = fp.first;
                int val = fp.second;
                if (node->left) {
                    dq.push_back(make_pair(node->left, ((2*val)-1)));
                }
                if (node->right) {
                    dq.push_back(make_pair(node->right,(2*val)));
                }
            }
        }
        return result;
    }
}

class Solution {
public:
    struct TT {
        TreeNode* node;
        int left;
        TT(TreeNode* n, int l) : node(n), left(l) {}
    };

    void print(vector<TT> & nn) {
        for (auto n : nn) {
            printf("%d:%d\t", n.left, n.node ? n.node->val : -1);
        }
        printf("\n");
    }

    int compute_len(vector<TT>& nn) {
        vector<TT> nnn;
        int sum = 0;;
        int acc_left= 0;
        bool first_flag = true;
        for (auto n : nn) {
            if (n.node) {
                if (first_flag) {
                    nnn.push_back(TT(n.node, 0));
                    sum = 1;
                    first_flag = false;
                } else {
                    nnn.push_back(TT(n.node, n.left + acc_left));
                    sum += n.left + acc_left + 1;
                }
                acc_left = 0;
            } else {
                acc_left += n.left;
            }
        }
        nn = nnn;
        return sum;
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<TT> nn;
        int length = 0;
        if (root) {
            nn.push_back(TT(root, 0));
            length = 1;
        }
        while (nn.size()) {
            vector<TT> nnn;
            print(nn);
            for (auto n : nn) {
                if (n.node) {
                    if (n.node->left) {
                        nnn.push_back(TT(n.node->left, 2*n.left));
                        if (n.node->right) {
                            nnn.push_back(TT(n.node->right, 0));
                        } else {
                            nnn.push_back(TT(NULL, 1));
                        }
                    } else {
                        if (n.node->right) {
                            nnn.push_back(TT(n.node->right, 2*n.left + 1));
                        } else {
                            nnn.push_back(TT(NULL, 2*(n.left+1)));
                        }
                    }
                } else {
                    //
                }
            }
            print(nnn);
            int ll = compute_len(nnn);
            print(nnn);
            printf("\n");
            length = max(ll, length);
            nn = nnn;
        }
        return length;
    }
};

int main()
{
    Solution s;
    TreeNode* node = init_tree_node({1,1,1,1,INT_MAX,INT_MAX,1,1,INT_MAX,INT_MAX,1});
    int ret = s.widthOfBinaryTree(node);
    trace(ret);
    return 0;
}
