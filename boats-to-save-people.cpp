//
// @lc app=leetcode.cn id=211530756 lang=cpp
//
// [211530756] boats-to-save-people [救生艇]
//
class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int i=0,j=p.size()-1;
        int ans=0;
        while(i<=j){
            if(p[i]+p[j]>limit){
                j-=1;
            }else{
                i+=1;
                j-=1;
            }
            ans+=1;
        }
        return max(ans,1);
    }
};
// @lc code=end