//
// @lc app=leetcode.cn id=186790299 lang=cpp
//
// [186790299] minimum-window-substring [最小覆盖子串]
//
class Solution {
public:
    unordered_map<char,int> mem;
    //unordered_set<char> in;
    string minWindow(string s, string t) {
        if(s.size()<t.size() ) return "";
        for(auto c:t) mem[c]+=1;
        int l=-1;
        int r=-1;

        int len=s.size();
        int sz=0;
        for(int i=0,j=0;j<s.size();j++){
            while(sz<t.size()&&i<s.size()){
                if(mem.count(s[i])){
                    if(mem[s[i]]>0){
                        sz+=1;
                    }
                    mem[s[i]]-=1;
                }
                i+=1;
            }
            if(sz==t.size()){
                while(j<i){
                    if(mem.count(s[j])){
                        if(mem[s[j]]==0){
                            break;
                        }else{
                            mem[s[j]]+=1;
                        }
                    }
                    j+=1;
                }
                //cout<<"j"<<j<<" i"<<i<<endl;
                len=min(len,i-j);
                if(len==i-j) l=j,r=i;
                mem[s[j]]+=1;
                sz-=1;
            }
        }
        string ret;
        if(l!=-1){
        for(;l<r;++l) ret+=s[l];
        return ret;
        }
        //cout<<"len"<<len<<endl;

        return "";
    }
};
// @lc code=end