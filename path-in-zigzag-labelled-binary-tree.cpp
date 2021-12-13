//
// @lc app=leetcode.cn id=200956868 lang=cpp
//
// [200956868] path-in-zigzag-labelled-binary-tree [二叉树寻路]
//
class Solution {
public:
    static const int N=1024*1024+10;
    int tree[N];
    int qsi(int a,int b){
        int res=1;
        while(b){
            if(b&1) res*=a;
            b>>=1;
            a=a*a;
        }
        return res;
    }
    vector<int> pathInZigZagTree(int label) {
        if(label==1) return{1};
        int i=2;
        bool flag=false;
        int tmp=4;
        tree[1]=1;
        while(i<=label){
            auto v=i;
            if(flag)
            for(auto j=i;j<tmp;++j){
                tree[j]=v;
                if(tree[j]==label){
                    vector<int> ret;
                    while(j){
                        ret.push_back(tree[j]);
                        j/=2;
                    }
                    reverse(ret.begin(),ret.end());
                    return ret;
                }
                v+=1;
            }
            else
            for(auto j=tmp-1;j>=i;j--){
                tree[j]=v;
                if(tree[j]==label){
                    vector<int> ret;
                    while(j){
                        ret.push_back(tree[j]);
                        j/=2;
                    }
                    reverse(ret.begin(),ret.end());
                    return ret;
                }
                v+=1;
            }
            i=v;
            flag=!flag;
            tmp*=2;
        }
        return {};
    }
};
// @lc code=end