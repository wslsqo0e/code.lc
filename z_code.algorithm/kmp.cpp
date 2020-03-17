/*************************************************************************
> File Name:  kmp.cpp
> Author: shenming
> Created Time: Thu Feb 20 10:37:39 2020
************************************************************************/

#include "common_lc.h"

// 暴力匹配算法
int ViolentMatch(string s, string p)
{
    int sLen = s.size();
    int pLen = p.size();

    int i = 0;
    int j = 0;

    while (i < sLen && j < pLen) {
        if (s[i] == s[j]) {
            //如果当前字符匹配成功（即S[i] == P[j]），则i++，j++
            i++;
            j++;
        } else {
            //如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0
            // p 回溯 j 位   s 回溯 j-1 位
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == pLen) {
        return i - j;  // 返回匹配位置
    } else {
        return -1;
    }
}

// next 数组的意义, next[j] = k  代表j之前(不包含j)的字符串有最大程度为 k 的相同前缀后缀
void generate_next(vector<int>& next, string s)
{
    next.clear();
    int N = s.size();
    next.resize(N);

    int j = 0;
    int k = -1;
    next[0] = -1;
    while (j < N - 1) {
        if (k == -1 || s[j] == s[k]) {
            j++; k++;
            next[j] = k;
        } else {
            k = next[k];
        }
        printf("k=%d, j=%d next[%d]=%d\n", k, j, j, next[j]);
    }
}

int KmpSearch(string s, string p)
{
    int sLen = s.size();
    int pLen = p.size();
    int i = 0;
    int j = 0;
    vector<int> next;
    generate_next(next, p);
    while (i < sLen && j < pLen) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == pLen) {
        return i - j;
    } else {
        return -1;
    }
}

int main()
{
    // string s = "abacdababc";
    string s = "abac";
    vector<int> next;
    generate_next(next, s);
    print_vec<int>(next);
    return 0;
}
