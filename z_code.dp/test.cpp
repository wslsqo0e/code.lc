/*************************************************************************
> File Name:  test.cpp
> Author: shenming
> Created Time: Wed Feb  5 15:09:17 2020
************************************************************************/

int knapsack(vector<int> v, vector<int> w, int n, int C)
{
    vector<vector<int>> f(n, vector<int>(C+1));

    for (int j = 1; j <=C; j++) {
        if (j >= w[0]) {
            f[0][j] = v[0];
        } else {
            f[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= C; j++) {
            if (j < w[i]) {
                f[i][j] = f[i-1][j];
            } else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    return f[n-1][C];
}

int knapsack(vector<int> v, vector<int> w, int n, int C){
    vector<int> f(C + 1);

    for(int i = 0; i < n; i++){
        for(int j = C; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    return f[C];
}
