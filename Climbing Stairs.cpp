class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};
//利用b存储累加之后的值
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n>1) {
            b += a;
            a = b - a;
            n--;
        }
        return b;
    }
};