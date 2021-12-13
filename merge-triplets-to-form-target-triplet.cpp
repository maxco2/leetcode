//
// @lc app=leetcode.cn id=186266031 lang=cpp
//
// [186266031] merge-triplets-to-form-target-triplet [合并若干三元组以形成目标三元组]
//
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tr, vector<int>& t) {
        int i=0;
        int cur[3]={-1,-1,-1};
        while(i<tr.size()){
            if(tr[i][0]<=t[0]&&tr[i][1]<=t[1]&&tr[i][2]<=t[2]){
                cur[0]=max(tr[i][0],cur[0]);
                cur[1]=max(tr[i][1],cur[1]);
                           cur[2]=max(cur[2],tr[i][2]);
                
            }
            i+=1;
        }
        if(cur[0]==t[0]&&cur[1]==t[1]&&cur[2]==t[2]){
            return true;
        }
        return false;
        
    }
};
// @lc code=end