//
// @lc app=leetcode.cn id=203473654 lang=cpp
//
// [203473654] permutation-sequence [排列序列]
//
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
      for(int i=1;i<=n;i++){
          ret+='0'+i;
      }
      for(int i=1;i<k;++i)
      next_permutation(ret.begin(),ret.end());
      return ret;
    }
};
// @lc code=end