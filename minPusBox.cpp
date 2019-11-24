/*************************************************************************
    > File Name:  minPusBox.cpp
    > Author: shenming
    > Created Time: Sat Nov 23 12:35:07 2019
************************************************************************/
// https://leetcode.com/contest/weekly-contest-163/problems/minimum-moves-to-move-a-box-to-their-target-location/

#include "lc_common.h"
using namespace std;

class Solutino_ref {
    // 什么时候用BFS, 什么时候用DFS，以及该怎么用
public:
    //direction vector
    vector<vector<int>> dir {{0,1},{0,-1},{1,0},{-1,0}};

    int minPushBox(vector<vector<char>>& grid) {
        //rows, cols
        int N = grid.size();
        int M = grid[0].size();

        //intitial position
        int target=-1, box =-1, player = -1;

        //calcluate distance of target, box, player in grid
        for(int i=0; i<N;i++){
            for(int j=0;j <M;j++){
                if(grid[i][j]=='S'){
                    player =i*M + j;
                }
                if(grid[i][j]=='B'){
                    box = i*M + j;
                }
                if(grid[i][j]=='T'){
                    target = i*M + j;
                }
            }
        }

        //set stl to track player-box movement
        //if already visited same path, ignore it
        set<pair<int, int>> visited;
        visited.insert({player, box});

        //declare queue for BFS
        //move box to all it's eligible neighbor
        queue<pair<int,int>> q;
        q.push({player, box});

        int ans = 0;
        while (!q.empty()) {
            // BFS search
            ans++;

            //size of neighbor to be visited
            int size = q.size();
            while (size--) {
                auto f = q.front();
                q.pop();

                //current box position
                int box_curr = f.second;
                //get box position in matrix
                int box_x = box_curr/ M;
                int box_y = box_curr % M;
                //palyer position
                int p = f.first;

                //make grid with box as obstacle
                grid[box_x][box_y] = '#';

                for (auto &d : dir) {
                    int new_box_x = box_x + d[0];
                    int new_box_y = box_y + d[1];

                    int px = box_x - d[0];
                    int py = box_y - d[1];

                    //to be used in dfs walk by player to reach box
                    vector<vector<int>> walk(N, vector<int>(M, 0));

                    if(isValid(grid, new_box_x, new_box_y) && canWalk(grid, p/M, p %M, px, py, walk) && visited.count({px * M + py, new_box_x*M + new_box_y})==0){

                        if(new_box_x == target/M && new_box_y==target%M)
                            return ans;

                        visited.insert({px * M + py, new_box_x * M + new_box_y});
                        q.push({px * M + py, new_box_x * M + new_box_y});
                    }
                }
            }
        }
    }

    bool isValid(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i>=grid.size() || j <0 || j>=grid[0].size() || grid[i][j]=='#')
            return false;

        return true;
    }

    bool canWalk(vector<vector<char>>& grid, int x, int y, int i, int j, vector<vector<int>>& walk){
        // DFS search
        if(x==i && y==j)
            return true;

        for(auto &d: dir){
            int nx = x + d[0], ny = y+d[1];
            if(isValid(grid, nx, ny) && walk[nx][ny] == 0){
                walk[nx][ny] = 1;
                if(canWalk(grid, nx, ny, i, j, walk))
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    // 采用了stack 其实是深度优先搜索，但该问题明显是广度优先搜索更合适
    size_t m, n;
    struct block {
        char type;
        bool can_reach;
        int least_dist;
    };

    typedef pair<int, int> pos;
    typedef pair<pos, pos> sb;

    inline bool is_floor(vector<vector<block>>& bg, int i, int j, pos b) {
        if (i == b.first && j == b.second) {
            return false;
        }

        if (bg[i][j].type != '#')
            return true;
        return false;
    }

    void fresh_reach(vector<vector<block>>& bg, pos s, pos b)
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bg[i][j].can_reach = 0;
            }
        }

        bg[s.first][s.second].can_reach = 1;
        stack<pos> remain;
        remain.push(s);
        while (remain.size()) {
            pos cur = remain.top();
            remain.pop();

            // printf("\t %d\n", remain.size());
            // printf("\tcur: %d %d\n", cur.first, cur.second);

            if (cur.first + 1 < m && is_floor(bg, cur.first+1, cur.second, b) && !bg[cur.first + 1][cur.second].can_reach) {
                bg[cur.first + 1][cur.second].can_reach = 1;
                pos next;
                next.first = cur.first + 1;
                next.second = cur.second;
                remain.push(next);
                // printf("\t1push: %d %d\n", next.first, next.second);
            }

            if (cur.first - 1 >= 0 && is_floor(bg, cur.first-1, cur.second, b) && !bg[cur.first - 1][cur.second].can_reach) {
                bg[cur.first - 1][cur.second].can_reach = 1;
                pos next;
                next.first = cur.first - 1;
                next.second = cur.second;
                remain.push(next);
                // printf("\t2push: %d %d\n", next.first, next.second);
            }

            if (cur.second - 1 >= 0 && is_floor(bg, cur.first, cur.second-1, b) && !bg[cur.first][cur.second - 1].can_reach) {
                bg[cur.first][cur.second - 1].can_reach = 1;
                pos next;
                next.first = cur.first;
                next.second = cur.second - 1;
                remain.push(next);
                // printf("\t3push: %d %d\n", next.first, next.second);
            }
            if (cur.second + 1 < n && is_floor(bg, cur.first, cur.second+1, b) && !bg[cur.first][cur.second + 1].can_reach) {
                bg[cur.first][cur.second + 1].can_reach = 1;
                pos next;
                next.first = cur.first;
                next.second = cur.second + 1;
                remain.push(next);
                // printf("\t4push: %d %d\n", next.first, next.second);
            }
        }
    }

    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<block>> bg;
        bg.resize(m);
        for (auto i = bg.begin(); i != bg.end(); i++) {
            i->resize(n);
        }

        pos s;
        pos b;
        pos t;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bg[i][j].type = grid[i][j];
                bg[i][j].least_dist = -1;
                if (bg[i][j].type == 'S') {
                    s.first = i;
                    s.second = j;
                }
                if (bg[i][j].type == 'B') {
                    b.first = i;
                    b.second = j;
                    bg[i][j].least_dist = 0;
                }
                if (bg[i][j].type == 'T') {
                    t.first = i;
                    t.second = j;
                }
            }
        }

        // 本质是最短路径算法
        sb src_box;
        src_box.first = s;
        src_box.second = b;
        stack<sb> remain;
        remain.push(src_box);
        while (remain.size()) {
            sb cur = remain.top();
            remain.pop();

            // printf("brfore s:[%d %d]  b:[%d %d]\n", cur.first.first, cur.first.second, cur.second.first, cur.second.second);
            fresh_reach(bg, cur.first, cur.second);
            // for (auto i = bg.begin(); i != bg.end(); i++) {
            //     for (auto j = i->begin(); j != i->end(); j++) {
            //         printf("%d ", j->can_reach);
            //     }
            //     printf("\n");
            // }
            int h_m = cur.second.first;
            int u = h_m  - 1;
            int d = h_m  + 1;
            // printf("%d %d %d\n", h_m, u, d);

            int v_m = cur.second.second;
            int l = v_m - 1;
            int r = v_m + 1;
            // printf("%d %d %d\n", v_m, l, r);
            if (l >= 0 && r < n && bg[h_m][l].type != '#' && bg[h_m][r].can_reach) {
                if (bg[h_m][l].least_dist < 0 || bg[h_m][v_m].least_dist + 1 < bg[h_m][l].least_dist) {
                    bg[h_m][l].least_dist = bg[h_m][v_m].least_dist + 1;
                    sb next;
                    next.first = cur.second;
                    next.second = pos(h_m, l);
                    remain.push(next);
                }
            }
            if (l >= 0 && r < n && bg[h_m][r].type != '#' && bg[h_m][l].can_reach) {
                if (bg[h_m][r].least_dist < 0 || bg[h_m][v_m].least_dist + 1 < bg[h_m][r].least_dist) {
                    bg[h_m][r].least_dist = bg[h_m][v_m].least_dist + 1;
                    sb next;
                    next.first = cur.second;
                    next.second = pos(h_m, r);
                    remain.push(next);
                }
            }
            if (u >= 0 && d < m && bg[u][v_m].type != '#' && bg[d][v_m].can_reach) {
                if (bg[u][v_m].least_dist < 0 || bg[h_m][v_m].least_dist + 1 < bg[u][v_m].least_dist) {
                    bg[u][v_m].least_dist = bg[h_m][v_m].least_dist + 1;
                    sb next;
                    next.first = cur.second;
                    next.second = pos(u, v_m);
                    remain.push(next);
                }
            }
            if (u >= 0 && d < m && bg[d][v_m].type != '#' && bg[u][v_m].can_reach) {
                if (bg[d][v_m].least_dist < 0 || bg[h_m][v_m].least_dist + 1 < bg[d][v_m].least_dist) {
                    bg[d][v_m].least_dist = bg[h_m][v_m].least_dist + 1;
                    sb next;
                    next.first = cur.second;
                    next.second = pos(d, v_m);
                    remain.push(next);
                }
            }
        }
        return bg[t.first][t.second].least_dist;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    // vector<vector<char>> grid = {
    //     {'#','#','#','#','#','#'},
    //     {'#','T','.','.','#','#'},
    //     {'#','.','#','B','.','#'},
    //     {'#','.','.','.','.','#'},
    //     {'#','.','.','.','S','#'},
    //     {'#','#','#','#','#','#'}
    // };

    // vector<vector<char>> grid = {{'#','#','#','#','#','#'},
    //                              {'#','T','#','#','#','#'},
    //                              {'#','.','.','B','.','#'},
    //                              {'#','.','#','#','.','#'},
    //                              {'#','.','.','.','S','#'},
    //                              {'#','#','#','#','#','#'}};
    // vector<vector<char>> grid = {{'#','#','#','#','#','#'},
    //                              {'#','T','#','#','#','#'},
    //                              {'#','.','.','B','.','#'},
    //                              {'#','#','#','#','.','#'},
    //                              {'#','.','.','.','S','#'},
    //                              {'#','#','#','#','#','#'}};
    // vector<vector<char>> grid = {{'#','#','#','#','#','#','#'},
    //                              {'#','S','#','.','B','T','#'},
    //                              {'#','#','#','#','#','#','#'}};
    vector<vector<char>> grid = {{'#','.','.','#','#','#','#','#'},
                                 {'#','.','.','T','#','.','.','#'},
                                 {'#','.','.','.','#','B','.','#'},
                                 {'#','.','.','.','.','.','.','#'},
                                 {'#','.','.','.','#','.','S','#'},
                                 {'#','.','.','#','#','#','#','#'}};

    for (auto i = grid.begin(); i != grid.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            printf("%c ", *j);
        }
        printf("\n");
    }

    int ret = s.minPushBox(grid);
    printf("%d\n", ret);
}
