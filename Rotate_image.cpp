/*************************************************************************
> File Name:  Rotate_image.cpp
> Author: shenming
> Created Time: Sun Jan 26 15:48:53 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    pair<float, float> rotate_index(pair<float, float>& index) {
        float a = index.second;
        float b = -index.first;
        pair<float, float> new_index(a, b);
        return new_index;
    }


    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        float mid = (n-1)/2.0;

        for (int i = 0; i < n-1; i++) {
            for (int j = i; j <n-1-i; j++) {
                // printf("i, j, %d, %d\n", i, j);
                int temp = matrix[i][j];
                int a = i;
                int b = j;
                int m = i;
                int n = j;
                for (int k = 0; k < 3; k++) {
                    // pair<float, float> index(i - mid, j - mid);
                    pair<float, float> index(n - mid, m - mid);
                    pair<float, float> new_index = rotate_index(index);
                    b = round(new_index.first + mid);
                    a = round(new_index.second + mid);
                    matrix[m][n] = matrix[a][b];
                    m = a;
                    n = b;
                }

                matrix[m][n] = temp;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3,}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    for (auto i : matrix) {
        for (auto j : i) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
    s.rotate(matrix);
    for (auto i : matrix) {
        for (auto j : i) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
