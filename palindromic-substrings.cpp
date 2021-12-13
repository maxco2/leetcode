//
// @lc app=leetcode.cn id=194629632 lang=cpp
//
// [194629632] palindromic-substrings [回文子串]
//
class Solution {
public:
    int check(string& s,int mid){
        int res=1;
        for(int i=mid-1,j=mid+1;i>=0&&j<s.size();++j,--i){
            if(s[i]==s[j]) res++;
            else break;
        }
        for(int i=mid,j=mid+1;i>=0&&j<s.size();++j,--i){
            if(s[i]==s[j]) res++;
            else break;
        }
        return res;
    }

    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            res+=check(s,i);
        }
        
        return res;

    }
};
// @lc code=end