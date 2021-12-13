//
// @lc app=leetcode.cn id=186222032 lang=cpp
//
// [186222032] first-bad-version [第一个错误的版本]
//
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l=1;
        long r=n;
        int ans=n;
        while(l<=r){
            int mid=l+r>>1;
            if(isBadVersion(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};
// @lc code=end