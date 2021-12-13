//
// @lc app=leetcode.cn id=195079147 lang=cpp
//
// [195079147] task-scheduler [任务调度器]
//
class Solution {
public:
    int cnt[26];
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        memset(cnt,0,sizeof cnt);
        for(auto c:tasks) cnt[c-'A']++;
        sort(cnt,cnt+26,[](int a,int b){return a>b;});
        int col=0;
        while(col<26&&cnt[col]==cnt[0]) col++;
        return max((int)(tasks.size()),col+(n+1)*(cnt[0]-1));
    }
};
// @lc code=end