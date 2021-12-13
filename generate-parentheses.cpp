//
// @lc app=leetcode.cn id=176927568 lang=cpp
//
// [176927568] generate-parentheses [括号生成]
//
class Solution {
public:
    vector<string> ret;
    void dfs(int n,int l,int r,string& s){
        if(l==r&&l==n){
            ret.push_back(s);
            return;
        }
        if(l<n){
            s+='(';
            dfs(n,l+1,r,s);
            s.pop_back();
        }
        if(r<l){
            s+=')';
            dfs(n,l,r+1,s);
            s.pop_back();
        }
    }
    string s;
    vector<string> generateParenthesis(int n) {
        ret.clear();
        s.clear();
        dfs(n,0,0,s);
        return ret;

    }
};
// @lc code=end