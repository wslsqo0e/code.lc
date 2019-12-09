// very cool
class {
public:
    int arrLen;
    vector<vector<int>> memo;
    int dp(int i, int steps)
    {
        // i==0 steps为1时，显然结果为1，同理 i == 0 steps == 0，什么都不做，也可以看做是一种方式，能够一致
        if (i == 0 && steps == 0) {
            return 1;
        }
        if (i < 0 || i >= this->arrLen) {
            return 0;
        }
        // if (steps == 0 && i != 0) {  // 无用的判断
        if (steps == 0) {
            return 0;
        }
        if (i > steps) {  // 显然需要裁剪的部分
            return 0;
        }
        return dp(i-1, steps-1) + dp(i+1, steps-1) + dp(i, steps)
    }

public:
    int numWays(int steps, int arrLen) {
        memo.resize(steps/2+1,vector<int>(steps+1,-1));
        this->arrLen = arrLen;
        return dp(0, steps);
    }
};
