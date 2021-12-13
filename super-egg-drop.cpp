//
// @lc app=leetcode.cn id=11984526 lang=cpp
//
// [11984526] super-egg-drop [鸡蛋掉落]
//
int dp[101][10001];
class Solution
{
public:
    int getcur(int k, int n, int i)
    {
        if (i < 0 || i > n) return INT_MAX;
        return max(dp[k - 1][i - 1], dp[k][n - i]);
    }
    bool check(int k, int n, int i) { return dp[k - 1][i - 1] > dp[k][n - i]; }

    int superEggDrop(int K, int N)
    {
        for (int i = 1; i <= N; ++i)
            dp[1][i] = i;
        for (int i = 1; i <= K; ++i)
            dp[i][1] = 1;
        for (int k = 2; k <= K; ++k)
            for (int n = 2; n <= N; ++n)
                {
                    dp[k][n] = n + 1;
                    int l = 1, r = n, ans = 1;
                    while (l <= r)
                        {
                            int mid = l + r >> 1;
                            if (check(k, n, mid))
                                ans = mid, r = mid - 1;
                            else
                                l = mid + 1;
                        }
                    dp[k][n] =
                        min(min(getcur(k, n, ans), getcur(k, n, ans - 1)),
                            getcur(k, n, ans + 1)) +
                        1;
                    // for (int i = 2; i <= n; ++i)
                    // dp[k][n] = min(dp[k][n],
                    // max(dp[k - 1][i - 1], dp[k][n - i]) + 1);
                }
        return dp[K][N];
    }
};
// @lc code=end