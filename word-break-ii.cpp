//
// @lc app=leetcode.cn id=196225506 lang=cpp
//
// [196225506] word-break-ii [单词拆分 II]
//
class Solution {
public:
    static const int N=3e5;
    int idx;
    int trie[N][26];
    bool st[N];
    vector<string> ret;

    void insert(string& s){
        int p=0;
        for(int i=0;i<s.size();++i){
            auto tmp=s[i]-'a';
            if(!trie[p][tmp]) trie[p][tmp]=++idx;
            p=trie[p][tmp];
        }
        st[p]=true;
    }

    bool search(string& s,int stt,int ed){
        int p=0;
        for(int i=stt;i<=ed;++i){
            auto tmp=s[i]-'a';
            if(!trie[p][tmp]) return false;
            p=trie[p][tmp];
        }
        return st[p];
    }
    void dfs(string& s,vector<pair<int,int>>& v,int cur){
        if(cur>=s.size()){
            string tmp;
            for(auto& p:v){
                tmp+=s.substr(p.first,p.second-p.first+1);
                tmp+=' ';
            }
            tmp.pop_back();
            ret.emplace_back(std::move(tmp));
            return;
        }
        for(int i=cur;i<s.size();++i){
            if(search(s,cur,i)){
                v.push_back({cur,i});
                dfs(s,v,i+1);
                v.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ret.clear();
        memset(st,0,sizeof st),idx=0;
        memset(trie,0,sizeof trie);
        for(auto& w:wordDict){
            insert(w);
        }
        vector<pair<int,int>> v;
        dfs(s,v,0);
        return ret;
    }
};
// @lc code=end