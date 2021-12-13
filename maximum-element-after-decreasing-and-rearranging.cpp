//
// @lc app=leetcode.cn id=195958042 lang=cpp
//
// [195958042] maximum-element-after-decreasing-and-rearranging [减小和重新排列数组后的最大元素]
//
static const int N=1e5+10;
class Solution {
public:
    int cnt[N];
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        int n = arr.size();
        memset(cnt,0,sizeof(int)*n);
        for (int v : arr) {
            ++cnt[min(v, n)];
        }
        int miss = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) {
                ++miss;
            } else {
                miss -= min(cnt[i] - 1, miss); // miss 不会小于 0，故至多减去 miss 个元素
            }
        }
        return n - miss;
    }
};

// @lc code=end