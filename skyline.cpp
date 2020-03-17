/*************************************************************************
> File Name:  skyline.cpp
> Author: shenming
> Created Time: Wed Jan 22 23:40:30 2020
# reference https://leetcode.com/problems/the-skyline-problem/discuss/479531/cpp14-solution-feel-free-to-ask-doubt  非常好的实现
************************************************************************/

#include "lc_common.h"

using namespace std;
typedef int ll;
typedef long double ld;
#define so sizeof
#define pb push_back
#define fi first
#define be begin()
#define en end()
#define se second
#define sz size()
#define vl vector<ll>
#define plvl pair<pair<ll,ll> ,ll>
#define forn(i,a,b) for(ll i=a;i<=b;++i)

struct op
{
    bool operator()(const plvl &a , const plvl &b)
    {
        if(a.fi.fi == b.fi.fi and a.se == 0 and b.se == 0) return a.fi.se > b.fi.se ;
        else if(a.fi.fi == b.fi.fi and a.se == 1 and b.se == 1) return a.fi.se < b.fi.se ;
        else if(a.fi.fi == b.fi.fi and a.se+b.se == 1) return a.se < b.se ;
        else return a.fi.fi < b.fi.fi ;
    }
};

class Solution_ref {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        ll n = buildings.size();
        vector<plvl> v;
        forn(i , 1 , n  ){
            ll li , ri , hi ;
            li = buildings[i-1][0] ;
            ri = buildings[i-1][1] ;
            hi = buildings[i-1][2] ;
            v.pb({{li , hi} , 0});
            v.pb({{ri , hi} , 1}) ;
        }
        sort(v.be , v.en , op());
        // set multiset 内部通过bst实现，可能红黑树，从 begin -> end 迭代是排序的
        multiset<ll> s ;  // 该数据结构刚好，类似于stack，但又提供排序功能
        ll maxx = 0 ;
        vector<vl> res ;
        for (auto x : v) {
            ll currht = x.fi.se ;
            ll what = x.se ;
            if(what == 0){   // left start
                // maxx  插入currht之前的最大高度
                // currmax 插入currht之后的最大高度，类似于当前outline的height
                // 如果两者不相等，显然新插入的承担一个拐点
                s.insert(currht);
                ll currmax = *s.rbegin();
                if(currmax != maxx){
                    maxx = *s.rbegin();
                    ll xi = x.fi.fi ;
                    ll yi = x.fi.se ;
                    vl foo ;
                    foo.pb(xi) ; foo.pb(yi) ;
                    res.pb(foo);
                }
            }
            else if(what == 1){  // right end
                if(s.sz) s.erase(s.find(currht)) ;
                ll currmaxx = 0 ;
                if(s.sz) currmaxx = *s.rbegin();
                if(currmaxx != maxx){
                    if(s.sz) maxx = *s.rbegin();
                    else maxx = 0 ;
                    ll xi = x.fi.fi ;
                    ll yi = maxx;
                    vl foo ;
                    foo.pb(xi) ; foo.pb(yi) ; res.pb(foo) ;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
   void combine_building(std::vector<std::vector<int>>& outline, std::vector<int>& build) {
       int l = build[0];
       int r = build[1];
       int h = build[2];
       std::vector<int> left;
       left.push_back(build[0]);
       left.push_back(build[2]);
       std::vector<int> right;
       right.push_back(build[1]);
       right.push_back(0);
       if (outline.size() == 0) {
           outline.push_back(left);
           outline.push_back(right);
           return;
       }
       int pre_h = 0;
       for (int i = 0; i < outline.size(); i++) {
           if (outline[i][0] < l) {
               if (i + 1 < outline.size() && outline[i+1][0] < l) {
                    pre_h = outline[i][1];
                    continue;
               }
               if (i + 1 == outline.size()) {
                   outline.push_back(left);
                   outline.push_back(right);
                   return;
               }
               if (outline[i+1][0] > l) {
                   if (outline[i][1] >= h) {
                       pre_h = outline[i][1];
                       continue;
                   } else {
                       pre_h = outline[i][1];
                       outline.insert(outline.begin() + i + 1, left);
                       i++;
                       continue;
                   }
               }
           } else if (outline[i][0] >= l && outline[i][0] < r) {
               pre_h = outline[i][1];
               outline[i][1] = outline[i][1] > h ?  outline[i][1] : h;
               continue;
           } else if (outline[i][0] > r && i-1>=0 && outline[i-1][0] < r) {
               if (pre_h >= h) {
                   break;
               } else {
                   right[1] = pre_h;
                   outline.insert(outline.begin() + i, right);
                   break;
               }
           }
       }
       if (outline[outline.size()-1][0] < r) {
           outline.push_back(right);
       }

       for (int i = 0; i < outline.size(); i++) {
           if (i > 0 && outline[i][1] == outline[i-1][1]) {
               outline.erase(outline.begin() + i);
               i--;
           }
       }

       return;
   }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::vector<std::vector<int>> outlines;
        for (auto i : buildings) {
            combine_building(outlines, i);
        }
        return outlines;
    }
};

int main()
{
    // Solution s;
    Solution_ref s;
    std::vector<std::vector<int>> buildings = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    std::vector<std::vector<int>> buildings_temp(buildings.begin(), buildings.begin() + 3);
    std::vector<std::vector<int>> ret = s.getSkyline(buildings);
    for (auto i : ret) {
        printf("%d %d\n", i[0], i[1]);
    }
}
