//
// @lc app=leetcode.cn id=199893357 lang=cpp
//
// [199893357] minimum-operations-to-make-a-subsequence [得到子序列的最少操作次数]
//
class Solution {
public:
    // f[]
    int minOperations(vector<int>& target, vector<int>& arr) {
        vector<int> a;
        unordered_map<int,int> mem;
        auto idx=0;
        for(auto n:target){
            mem[n]=idx++;
        }
        for(auto n:arr){
            if(mem.count(n)){
                a.push_back(mem[n]);
                //cout<<mem[n]<<" ";
            }
        }
        //cout<<endl;printf("tar size:%ld\n",target.size());
        if(a.empty()) return target.size();
        vector<int> dp(a.size()+1,INT_MAX);
        dp[1]=a[0];
        auto len=1;
        for(int i=1;i<a.size();++i){
            int l=1;
            int r=len;
            int ans=l;
            if(a[i]>dp[len]){
                dp[++len]=a[i];
                //printf("len %d min v:%d\n",len,a[i]);

                continue;
            }else if(a[i]==dp[len]){
                continue;
            }
            while(l<=r){
                int mid=l+r>>1;
                if(dp[mid]>=a[i]) ans=mid,r=mid-1;
                else l=mid+1;
            }
            //printf("len %d min v:%d\n",ans,a[i]);
            dp[ans]=a[i];
        }
        return target.size()-len;
    }
};
// @lc code=end