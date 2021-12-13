//
// @lc app=leetcode.cn id=216664689 lang=cpp
//
// [216664689] decode-ways [解码方法]
//
class Solution {
public:
    using pii=pair<int,int>;
    map<pii,int> mem;
    int dfs(int cur,int idx,string& s,int v){
        pii key{cur,idx};
        if(mem.count(key)){
            return v+mem[key];
        }
        if(idx>=s.size()){
            if(cur==0)
            return v+1;
            else
            return v;
        }
        int c=s[idx]-'0';
        int tmp=v;
        if(cur==0&&c==0){
            mem[key]=0;
            return v;
        }
        if(cur==0){
            if(c<=2)
            v+=dfs(c,idx+1,s,0);
            v+=dfs(0,idx+1,s,0);
        }else{
            if(cur*10+c>=1&&cur*10+c<=26)
            v+=dfs(0,idx+1,s,0);
            else{
                mem[key]=v-tmp;
                return v;
            }
        }
        mem[key]=v-tmp;
        return v;
    }
    int numDecodings(string s) {
        return dfs(0,0,s,0);
    }
};
// @lc code=end