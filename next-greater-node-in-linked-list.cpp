/*************************************************************************
> File Name:  next-greater-node-in-linked-list.cpp
> Author: shenming
> Created Time: Tue Feb  4 00:10:58 2020
************************************************************************/

#include "common_lc.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        if (head == NULL) {
            return ret;
        }
        stack<pair<int, int>> st;
        int index = 0;
        st.push({head->val, index});
        ret.push_back(0);
        head = head->next;
        while (head) {
            int val = head->val;
            index++;
            while (!st.empty()) {
                if (val > st.top().first) {
                    ret[st.top().second] = val;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push({head->val, index});
            ret.push_back(0);
            head = head->next;
        }
        return ret;
    }
};
