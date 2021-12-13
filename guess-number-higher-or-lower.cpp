//
// @lc app=leetcode.cn id=186645056 lang=cpp
//
// [186645056] guess-number-higher-or-lower [猜数字大小]
//
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=1;
        long long r=n;
        int ans=n;
        while(l<=r){
            long long mid=l+r>>1;
            int q=guess(mid);
            if(q==0) return mid;
            if(q==1) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end