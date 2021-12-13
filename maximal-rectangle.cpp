//
// @lc app=leetcode.cn id=212719719 lang=cpp
//
// [212719719] maximal-rectangle [最大矩形]
//
class Solution {
public:
static const int N=210;
int l1[N][N];
int left[N];
int right[N];
int st[N];
    int maximalRectangle(vector<vector<char>>& ma) {
        if(ma.empty()) return 0;
        int m=ma.size();
        int n=ma[0].size();
        if(n==0) return 0;
        for(int i=0;i<m;++i){
            if(ma[i][0]=='1')
            l1[i][0]=1;
            for(int j=1;j<n;++j){
                if(ma[i][j]=='1'){
                    l1[i][j]=l1[i][j-1]+1;
                }
            }
        }
        int res=0;
        for(int j=0;j<n;++j){
            //col
            memset(left,-1,sizeof left);
            for(int j=0;j<m;++j) right[j]=m;
            int top=0;
            for(int i=0;i<m;++i){
                while(top>0&&l1[st[top-1]][j]>=l1[i][j]){
                    right[st[--top]]=i;
                }
                if(top>0) left[i]=st[top-1];
                st[top++]=i;
            }
            for(int i=0;i<m;++i){
                res=max(res,(right[i]-left[i]-1)*l1[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end