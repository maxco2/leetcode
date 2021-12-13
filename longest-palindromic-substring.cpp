//
// @lc app=leetcode.cn id=168789745 lang=cpp
//
// [168789745] longest-palindromic-substring [最长回文子串]
//
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //even s[0..len/2]==s[(len-1>>2)+1..]
    //odd  s[0..len/2]==s[len/2+1..]
    //dp[0..len]
    string longestPalindrome(string s)
    {
        if (s.empty()) return "";
        auto check = [&s](int l, int r) {
            if (l == r) return true;
            while (l < r)
                {
                    if (s[l++] != s[r--]) return false;
                }
            return true;
        };
#define MAXR 2
#define MAXC 1005
        int dp[MAXR][MAXC];
        int lcs = 0;
        int l = 0, r = 0;
        memset(dp, 0, sizeof(int) * MAXR * MAXC);
        auto sz = s.size();
        int cur = 0;
        for (int i = 0; i < sz; ++i, cur = !cur)
            {
                for (int j = sz - 1; j >= 0; j--)
                    {
                        int next = !cur;
                        if (s[j] == s[i])
                            {
                                int tmplen = dp[next][sz - j] =
                                    dp[cur][sz - j - 1] + 1;
                                if (dp[next][sz - j] > lcs &&
                                    check(i - tmplen + 1, i))
                                    {
                                        lcs = dp[next][sz - j];
                                        l = i;
                                        r = j;
                                    }
                            }
                        else
                            {
                                dp[next][sz - j] = 0;
                            }
                    }
            }
        return string{s.begin() + l - lcs + 1, s.begin() + l + 1};
    }
};
// @lc code=end