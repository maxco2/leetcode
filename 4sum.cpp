//
// @lc app=leetcode.cn id=172067687 lang=cpp
//
// [172067687] 4sum [四数之和]
//
class Solution {
public:
    int sz;
    void dfs(vector<int>& nums,vector<vector<int>>& ret,int target,vector<int>& cur,int cursum,int idx){
        if(cur.size()==4){
            if(cursum==target)
            ret.push_back(cur);
            return;
        }
        if(cur.size()==3){
            int remain=target-cursum;
            int l=idx;
            int r=sz-1;
            int ans=r;
            if(l>r) return ;
            while(l<=r){
                int mid=l+r>>1;
                if(nums[mid]>=remain) ans=mid,r=mid-1;
                else l=mid+1;
            }
            if(nums[ans]==remain){
                cur.push_back(remain);
                ret.push_back(cur);
                cur.pop_back();
                return;
            }
            return;
        }
        for(int i=idx;i<sz;++i){
            if(i>idx&&nums[i]==nums[i-1]) continue;
            auto cursz=cur.size();
            cur.push_back(nums[i]);
            dfs(nums,ret,target,cur,cursum+nums[i],i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=3) return {};
        sz=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(nums,ret,target,cur,0,0);
        return ret;

    }
};
// @lc code=end