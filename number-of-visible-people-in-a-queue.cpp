//
// @lc app=leetcode.cn id=200285733 lang=cpp
//
// [200285733] number-of-visible-people-in-a-queue [队列中可以看到的人数]
//
class Solution {
public:
    static const int N=1e5+10;
    int st[N],top;
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ret(heights.size(),0);
        top=0;
        for(int i=0;i<heights.size();++i){
            while(top>0&&heights[st[top-1]]<=heights[i]){
                ret[st[top-1]]++;
                top--;
            }
            if(top>0) ret[st[top-1]]++;
            st[top++]=i;
        }
        return ret;
    }
};
// @lc code=end