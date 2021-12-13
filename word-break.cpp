//
// @lc app=leetcode.cn id=194833081 lang=cpp
//
// [194833081] word-break [单词拆分]
//
class Solution {
public:
     static const int N=1e4+100;
    int trie[N][26];
    bool cnt[N];
    int idx;
    void insert(string& s){
        int p=0;
        for(auto c:s){
            int tmp=c-'a';
            if(!trie[p][tmp]) trie[p][tmp]=++idx;
            p=trie[p][tmp];
        }
        cnt[p]=true;
    }
    bool indict(string& s,int st,int ed){
        int p=0;
        for(int i=st;i<=ed;++i){
            int tmp=s[i]-'a';
            if(!trie[p][tmp]) return false;
            p=trie[p][tmp];
        }
        return cnt[p];
    }
    bool indict(string& s,int st,int ed,int&p){
        if(p==-1) return false;
        {
            int tmp=s[ed]-'a';
            if(!trie[p][tmp]) {p=-1;return false;}
            p=trie[p][tmp];
        }
        return cnt[p];
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        memset(trie,0,sizeof trie);
        memset(cnt,0,sizeof cnt);
        idx=0;
        for(auto& v:wordDict){
            insert(v);
        }
        vector<bool> dp(s.size(),false);
        // 0<=j<i
        int p=0;
        for(int i=0;i<s.size();++i){
            dp[i]=indict(s,0,i,p);
            if(!dp[i])
            for(int j=0;j<i;++j){
                dp[i]=dp[j]&&indict(s,j+1,i);
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[s.size()-1];
    }
};
// @lc code=end