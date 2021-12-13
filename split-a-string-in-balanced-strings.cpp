//
// @lc app=leetcode.cn id=216198903 lang=cpp
//
// [216198903] split-a-string-in-balanced-strings [分割平衡字符串]
//
class Solution {
public:
    bool is(int l,int r){
        if(l==0&&r==0) return true;
        if(l==r) return false;
        return true;
    }
    int balancedStringSplit(string s) {
        int l=0;int r=0;int res=0;
        for(int i=0;i<s.size();++i){
            int j=i;
            while(j<s.size()&&is(l,r)){
                if(s[j]=='L') l++;
                else r++;
                //printf("l:%d,r:%d,j:%d\n",l,r,j);
                j++;
            }
            if(l!=0&&r!=0&&l==r){
                res++;
                l=r=0;
            }
            i=j-1;
        }
        return res;
    }
};
// @lc code=end