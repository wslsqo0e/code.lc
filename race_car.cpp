/*************************************************************************
> File Name:  race_car.h
> Author: shenming
> Created Time: Sat Jan 25 08:54:08 2020
************************************************************************/

#include "common_lc.h"

/*
 * state {speed remain} -> {speed*2 remain+speed}
 *                      -> {1 or -1 remain}
 */
class Solution {
public:
    int largest_move;
    map<pair<int, int>, int> mem;

    int get_minimum_steps(pair<int, int> state) {
        if ((state.first > 0 && state.second <0 ) ||
            (state.first <0 && state.second > 0)) {
            int step = log(abs(state.second) + 1)/log(2);
            return step;
        } else {
            int step = log(abs(state.second - 2* state.first))/log(2);
            return step;
        }
    }
    void trace(pair<int, int> state, int step) {
        // printf("[%d %d] %d\n", state.first, state.second, step);
        if (state.second == 0) {
            if (step < largest_move) {
                largest_move = step;
            }
            return;
        }
        //if (mem.count(state)) {
        //    if (mem[state] == INT_MAX) {
        //        return;
        //    } else {
        //        if (step + mem[state] < largest_move) {
        //            largest_move = step + mem[state];
        //        }
        //        return;
        //    }
        //}
        // A
        pair<int, int> a_state(state.first*2, state.second-state.first);
        // printf("a_state: %d, %d\n", a_state.first, a_state.second);
        if (step + 1 + get_minimum_steps(a_state) > largest_move) {
            // do nothing
        } else {
            trace(a_state, step + 1);
        }
        pair<int, int> r_state(state.first > 0 ? -1: 1, state.second);
        if (step + 1+ get_minimum_steps(r_state) > largest_move) {
            // do nothing
        } else {
            trace(r_state, step + 1);
        }
    }

    int racecar(int target) {
        pair<int, int> start(1, target);
        largest_move = 3*target;
        trace(start, 0);
        return largest_move;
    }
};

int main()
{
    Solution s;
    int ret = s.racecar(4);
    printf("%d\n", ret);
    return 0;
}
