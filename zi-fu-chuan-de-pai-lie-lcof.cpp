//
// @lc app=leetcode.cn id=180246754 lang=cpp
//
// [180246754] zi-fu-chuan-de-pai-lie-lcof [字符串的排列]
//
class Solution {
public:
    string cur;
    vector<string> ret;
    bool mem[9];
    void dfs(string& s){
        if(cur.size()==s.size()){
            ret.push_back(cur);
        }
        unsigned last=-1;
        for(int i=0;i<s.size();++i){
            if(!mem[i]&&s[i]!=last){
                last=s[i];
                mem[i]=true;
                cur.push_back(s[i]);
                dfs(s);
                cur.pop_back();
                mem[i]=false;
            }
        }
    }
    vector<string> permutation(string s) {
        cur.clear();
        ret.clear();
        sort(s.begin(),s.end());
        memset(mem,0,sizeof(mem));
        dfs(s);
        return ret;

    }
};
// @lc code=end