//
// @lc app=leetcode.cn id=189796221 lang=cpp
//
// [189796221] open-the-lock [打开转盘锁]
//
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> mem;
        for(auto&s: deadends) mem.insert(s);
        if(mem.count(target)) return -1;
        if(mem.count("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            //cout<<"cur s:"<<cur.first<<" d:"<<cur.second<<endl;
            auto& s=cur.first;
            auto d=cur.second;
            if(s==target) return d;
            for(int i=0;i<target.size();++i){
                //if(target[i]!=s[i]){
                    auto tmp=s[i]-'0';
                    auto n1='0'+(tmp+1)%10;
                    auto n2='0'+(tmp-1+10)%10;
                    s[i]=n1;
                    if(!mem.count(s)){
                        q.push({s,d+1});
                        mem.insert(s);
                    }
                    s[i]=n2;
                    if(!mem.count(s)){
                        q.push({s,d+1});
                        mem.insert(s);
                    }
                    s[i]='0'+tmp;
                //}
            }
        }
        return -1;
    }
};
// @lc code=end