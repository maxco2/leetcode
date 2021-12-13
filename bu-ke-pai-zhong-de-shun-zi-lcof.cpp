//
// @lc app=leetcode.cn id=179949122 lang=cpp
//
// [179949122] bu-ke-pai-zhong-de-shun-zi-lcof [扑克牌中的顺子]
//
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=nums.size();
        int diff=0;
        if(nums.back()==0) return true;//all zero

        //not all zero
        for(int i=nums.size()-1;i>=1;i--){
            auto ni=nums[i];
            auto nj=nums[i-1];
            if(ni==nj){//impossible
                return false;
            }
            if(ni&&nj){
                //cout<<ni<<" "<<nj<<endl;
                diff+=(ni-1-nj);
                count-=1;
                if(i==1)
                    count-=1;
            }else{
                if(ni!=0)
                    count-=1;
                break;
            }
        }
        //cout<<"diff:"<<diff<<"count:"<<count<<endl;
        if(diff==0||diff<=count){
            return true;
        }
        return false;
    }
};
// @lc code=end