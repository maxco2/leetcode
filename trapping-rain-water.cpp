//
// @lc app=leetcode.cn id=193924723 lang=cpp
//
// [193924723] trapping-rain-water [接雨水]
//
class Solution {
public:
static const int N=3e4+10;
int st[N];
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int res=0;
        int top=0;
        for(int i=0;i<height.size();++i){
            while(top>0&&height[st[top-1]]<=height[i]){
                auto th=height[st[top-1]];
                top--;
                if(top==0){
                    break;
                }
                //printf("left idx %d height:%d,right idx %d height:%d\n",st[top-1],height[st[top-1]],
                //i,height[i]
                //);
                //printf("width:%d,h:%d\n",(i-st[top-1]-1),(min(height[st[top-1]],height[i])-th));
                res+=(i-st[top-1]-1)*(min(height[st[top-1]],height[i])-th);
            }
            st[top++]=i;
        }
        return res;
    }
};

// @lc code=end