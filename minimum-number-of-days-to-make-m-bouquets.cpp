//
// @lc app=leetcode.cn id=175911073 lang=cpp
//
// [175911073] minimum-number-of-days-to-make-m-bouquets [制作 m 束花所需的最少天数]
//
class Solution {
public:
    int m;
    int k;
    int sz;
    bool mem[100005];
    bool check(vector<int>& by,int day){
        //cout<<"day"<<day<<endl;
        memset(mem,0,sizeof(mem));
        for(int i=0;i<sz;++i){
            if(day>=by[i]) mem[i]=true;
        }
        int mm=m;
        for(int i=0;i<sz&&mm>0;){
            if(mem[i]){
                int j=i+1;
                for(;j<sz&&j<i+k;++j){
                    if(!mem[j]){
                        break;
                    }
                }
                if(j==i+k) mm-=1;
                i=j;
            }else{
                i+=1;
            }
        }
        return mm==0;
    }

    int minDays(vector<int>& by, int _m, int _k) {
        sz=by.size();
        m=_m;k=_k;
        int minDays=INT_MAX;
        int maxDays=-1;
        for(auto n:by){
            minDays=min(n,minDays);
            maxDays=max(n,maxDays);
        }
        int l=minDays;
        int r=maxDays;
       // cout<<"l"<<l<<"r"<<r<<endl;
        int ans=-1;
        while(l<=r){
            int mid=l+r>>1;
            if(check(by,mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};
// @lc code=end