//
// @lc app=leetcode.cn id=191099017 lang=cpp
//
// [191099017] implement-trie-prefix-tree [实现 Trie (前缀树)]
//
class Trie {
public:
    static const int N=1e6+100;
    int trie[N][26];
    int cnt[N];
    int idx;
    /** Initialize your data structure here. */
    Trie() {
        memset(trie,0,sizeof trie);
        memset(cnt,0,sizeof cnt);
        idx=0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p=0;
        for(auto c:word){
            int i=c-'a';
            if(!trie[p][i]) trie[p][i]=++idx;
            p=trie[p][i];
        }
        cnt[p]++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p=0;
        for(auto c:word){
            int i=c-'a';
            if(!trie[p][i]) return false;
            p=trie[p][i];
        }
        return cnt[p]>0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p=0;
        for(auto c:prefix){
            int i=c-'a';
            if(!trie[p][i]) return false;
            p=trie[p][i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end