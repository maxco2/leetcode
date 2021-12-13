//
// @lc app=leetcode.cn id=212712863 lang=cpp
//
// [212712863] largest-rectangle-in-histogram [柱状图中最大的矩形]
//
class Solution {
public:
int top=0;
static const  int N=1e5+10;
int st[N];
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        for(int i=0;i<n;++i){
            while(top>0&&heights[st[top-1]]>=heights[i]){
                right[st[top-1]]=i;
                //printf("h[%d]=%d,r:%d\n",st[top-1],heights[st[top-1]],i);
                top--;
            }
            if(top>0) {
                left[i]=st[top-1];
                //printf("h[%d]=%d,l:%d\n",i,heights[i],st[top-1]);
            }
            st[top++]=i;
        }
        int res=0;
        for(int i=0;i<heights.size();++i){
            res=max(res,(right[i]-left[i]-1)*heights[i]);
        }
        return res;
        
    }
};
// @lc code=end