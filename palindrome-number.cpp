//
// @lc app=leetcode.cn id=168795408 lang=cpp
//
// [168795408] palindrome-number [回文数]
//
int n[35];
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int idx=0;
        while(x!=0){
            n[idx++]=x%10;
            x/=10;
        }
        for(int l=0,r=idx-1;l<r;l++,r--){
            if(n[l]!=n[r]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end