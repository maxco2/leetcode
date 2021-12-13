//
// @lc app=leetcode.cn id=189796697 lang=cpp
//
// [189796697] word-ladder [单词接龙]
//
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mem;
        for(auto&s:wordList) mem.insert(s);
        if(!mem.count(endWord)) return 0;
        unordered_set<string> vst;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        auto n=beginWord.size();
        while(!q.empty()){
            auto cur=q.front();q.pop();
            auto& s=cur.first;
            auto d=cur.second;
            if(s==endWord) return d;
            for(int i=0;i<n;++i){
                auto tmp=s[i];
                for(int j='a';j<='z';++j){
                    if(j!=s[i]){
                        s[i]=j;
                        if(mem.count(s)&&!vst.count(s)){
                            q.push({s,d+1});
                            vst.insert(s);
                        }
                        s[i]=tmp;
                    }
                }
            }
        }
        return 0;

    }
};
// @lc code=end