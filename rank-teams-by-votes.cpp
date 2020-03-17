/*************************************************************************
> File Name:  rank-teams-by-votes.cpp
> Author: shenming
> Created Time: Thu Mar  5 22:21:44 2020
************************************************************************/

#include "common_lc.h"
struct T {
    char C;
    vector<int> votes;
    T() {votes.resize(26); C = 0;}
};

bool less_fun(T& a, T& b) {
    int N = a.votes.size();
    for (int i = 0; i < N; i++) {
        if (a.votes[i] > b.votes[i]) {
            return true;
        } else if (a.votes[i] < b.votes[i]) {
            return false;
        }
        continue;
    }
    if (b.C < a.C) {
        return false;
    }
    return true;
    }

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        std::vector<T> teams(26);
        for (int i = 0; i < 26; i++) {
            teams[i].C = i + 'A';
        }
        for (auto s : votes) {
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                teams[c - 'A'].votes[i]++;
            }
        }
        sort(teams.begin(), teams.end(), less_fun);
        string ret;
        for (int i = 0; i < votes[0].size(); i++) {
            if (teams[i].C != 0) {
                ret += teams[i].C;
            } else {
                break;
            }
        }
        return ret;

    }
};

int main()
{
    Solution s;
    vector<string> ss = {"ABC","ACB","ABC","ACB","ACB"};
    string ret = s.rankTeams(ss);
    trace(ret);
    return 0;
}

// struct TT {
//     int i;
// }
// bool myfunction (int i,int j) { return (i<j); }//升序排列
// bool myfunction2 (int i,int j) { return (i>j); }//降序排列
//
// struct myclass {
//   bool operator() (int i,int j) { return (i<j);}
// } myobject;
//
// int main () {
//     int myints[8] = {32,33,12,45,26,80,53,33};
//   std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33
//
//   // using function as comp
//   std::sort (myvector.begin(), myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
//     //std::sort (myints,myints+8,myfunction);不用vector的用法
//
//   // print out content:
//   std::cout << "myvector contains:";
//   for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)//输出
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//
//   return 0;
// }
