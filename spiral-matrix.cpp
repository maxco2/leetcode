//
// @lc app=leetcode.cn id=179081803 lang=cpp
//
// [179081803] spiral-matrix [螺旋矩阵]
//
class Solution {
public:
    bool mem[105][105];
    vector<int> spiralOrder(vector<vector<int>>& mx) {
        int m=mx.size();
        if(!m) return {};
        int n=mx[0].size();
        if(!n) return {};
        memset(mem,0,sizeof(mem));
        vector<int> ret;
        int cm=0;
        int cn=0;
        int a=0;int sz=0;
        while(cm>=0&&cm<m&&cn>=0&&cn<n&&sz<m*n){
            ret.push_back(mx[cm][cn]);
            mem[cm][cn]=true;
            sz+=1;
            switch(a){
                case 0:
                    //right
                    if(cn+1<n){
                        cn+=1;
                        if(mem[cm][cn]){
                            a=(a+1)%4;
                            cn-=1;
                            cm+=1;
                        }
                    }else{
                        a=1;
                        cm+=1;
                    }
                    break;
                case 1:
                    //down
                    if(cm+1<m){
                        cm+=1;
                        if(mem[cm][cn]){
                            a=(a+1)%4;
                            cm-=1;
                            cn-=1;
                        }
                        
                    }else{
                        a=2;
                        cn-=1;
                    }
                    break;
                case 2:
                    //left
                    if(cn-1>=0){
                        cn-=1;
                        if(mem[cm][cn]){
                            a=(a+1)%4;
                            cn+=1;
                            cm-=1;
                        }
                    }else{
                        a=3;
                        cm-=1;
                    }
                    break;
                case 3:
                    //up
                    if(cm-1>=0){
                        cm-=1;
                        if(mem[cm][cn]){
                            a=(a+1)%4;
                            cn+=1;
                            cm+=1;
                        }
                    }else{
                        a=0;
                        cn+=1;
                    }
                    break;
                default:
                    break;
            }
            
        }
        return ret;

    }
};
// @lc code=end