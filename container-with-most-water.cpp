//
// @lc app=leetcode.cn id=168789717 lang=cpp
//
// [168789717] container-with-most-water [盛最多水的容器]
//
class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        // dp[1..n]=max(min(h[i],h[j])*(j-i))
        int l = 0, r = h.size() - 1;
        int res = 0;
        // n-1
        while (l <= r)
            {
                res = max(res, min(h[l], h[r]) * (r - l));
                if (h[l] < h[r])
                    l++;
                else
                    r--;
            }
        return res;
    }
};
// @lc code=end