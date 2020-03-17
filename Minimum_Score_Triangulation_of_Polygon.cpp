/*************************************************************************
> File Name:  Minimum_Score_Triangulation_of_Polygon.cpp
> Author: shenming
> Created Time: Sat Feb  1 11:34:23 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    map<pair<int, int>, int> mem;
    int dp(vector<int>&A, int b, int e) {
        if (e - b < 2) {
            return 0;
        }
        if (e - b == 2) {
            return A[b]*A[b+1]*A[b+2];
        }
        pair<int, int> key = {b, e};
        if (mem.count(key)) {
            return mem[key];
        }
        int res = 0;
        for (int i = b+1; i < e; i++) {
            int cc = A[b]*A[i]*A[e];
            int cc1 = dp(A, b, i);
            int cc2 = dp(A, i, e);
            cc += cc1 + cc2;
            if (res == 0) {
                res = cc;
            } else if (cc < res) {
                res = cc;
            }
        }
        mem[key] = res;
        return res;
    }

    int minScoreTriangulation(vector<int>& A) {
        int len = A.size();
        if (len < 3) {
            return 0;
        }
        if (len == 3) {
            return A[0]*A[1]*A[2];
        }
        return dp(A, 0, len-1);
    }

    // int minScoreTriangulation(vector<int>& A) {
    //     int len = A.size();
    //     if (len < 3) {
    //         return 0;
    //     }
    //     if (len == 3) {
    //         return A[0]*A[1]*A[2];
    //     }
    //     int res = 0;
    //     for (int i = 1; i < len-1; i++) {
    //         int cc = A[0]*A[len-1]*A[i];
    //         vector<int> A1(A.begin(), A.begin()+i+1);
    //         vector<int> A2(A.begin()+i, A.end());
    //         int cc1 = minScoreTriangulation(A1);
    //         int cc2 = minScoreTriangulation(A2);
    //         // printf("= %d += %d +  %d\n", cc, cc1, cc2);
    //         cc += cc1 + cc2;
    //         if (res == 0) {
    //             res = cc;
    //         }
    //         else if (cc <  res) {
    //             res = cc;
    //         }
    //     }
    //     return res;
    // }
};

int main()
{
    Solution s;
    vector<int> A = {1, 3, 1, 4, 1, 5};
    // vector<int> A = {3, 7, 4, 5};
    int ret = s.minScoreTriangulation(A);
    trace(ret);
    return 0;
}
