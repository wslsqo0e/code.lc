/*************************************************************************
> File Name:  longest-absolute-file-path.cpp
> Author: shenming
> Created Time: Mon Feb  3 17:43:19 2020
************************************************************************/
#include "common_lc.h"

class Solution {
public:
    struct FFF {
        string name;
        int len;
    };
    int lengthLongestPath(string input) {
        vector<vector<FFF>> depth;
        int cur_depth = 0;
        string cur_str = "";
        int max_len = 0;
        for (int i = 0; i < (int)input.size(); i++) {
            if (input[i] == '\n') {
                if (cur_depth >= (int)depth.size()) {
                    depth.push_back(vector<FFF>());
                }
                FFF ff;
                ff.name = cur_str;
                if (cur_depth == 0) {
                    ff.len = (int)cur_str.size();
                } else {
                    vector<FFF> ff_v = depth[cur_depth-1];
                    ff.len = ff_v[ff_v.size() - 1].len + 1 + cur_str.size();
                }
                depth[cur_depth].push_back(ff);
                cur_depth = 0;
                // printf("%d, %s %d\n",i, cur_str.c_str(), ff.len);
                if (cur_str.find('.') != string::npos) {
                    max_len = max(max_len, ff.len);
                }
                cur_str="";
            } else if (input[i] == '\t') {
                cur_depth++;
            } else {
                cur_str += input[i];
            }
        }
        if (cur_str.find('.') != string::npos) {
            int len = 0;
            if (cur_depth == 0) {
                len = (int)cur_str.size();
            } else {
                vector<FFF> ff_v = depth[cur_depth-1];
                len = ff_v[ff_v.size() - 1].len + 1 + cur_str.size();
            }
            // printf(" %s %d %d\n",cur_str.c_str(), max_len, len);
            max_len = max(max_len, len);
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    int ret = s.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    trace(ret);
    ret = s.lengthLongestPath("dir\n\t        file.txt\n\tfile2.txt");
    trace(ret);
    return 0;
}
