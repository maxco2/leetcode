//
// @lc app=leetcode.cn id=183442486 lang=cpp
//
// [183442486] jump-game [跳跃游戏]
//
class Solution {
public:
    int n;
    map<pair<int,int>,bool> mem;
    bool dfs(vector<int>& nums,int cur,int tar){
        //if(mem.count(pair<int,int>(cur,tar))){
        //    nums[-1];
        //    return mem[pair<int,int>(cur,tar)];
        //}
        //cout<<"cur"<<cur<<" "<<tar<<endl;
        if(nums[cur]>=tar-cur){
            if(cur==0){
                 mem.insert({pair<int,int>{cur,tar},true});
                return true;
            }
            bool res= dfs(nums,cur-1,cur);
            if(res)
            {
                 mem.insert({pair<int,int>{cur,tar},true});
                return true;
            }
        }else{
            if(cur==0){
        mem.insert({pair<int,int>{cur,tar},false});
                return false;
            }
            bool res=dfs(nums,cur-1,tar);
            if(res)
            {
            mem.insert({pair<int,int>{cur,tar},true});                
                return true;
            }
        }
        mem.insert({pair<int,int>{cur,tar},false});
        return false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        if(n==1) return true;
        return dfs(nums,n-2,n-1);
    }
};
// @lc code=end