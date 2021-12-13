//
// @lc app=leetcode.cn id=179612954 lang=cpp
//
// [179612954] xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof [旋转数组的最小数字]
//
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int ln=numbers[0];
        int r=numbers.size()-1;
        int rn=numbers[r];
        int l=0;
        int ans=min(ln,rn);
        while(l<=r){
            int mid=l+r>>1;
            ans=min(numbers[mid],ans);
            if(numbers[mid]<numbers[r]){
                r=mid-1;
            }else if(numbers[mid]>numbers[r]){
                l=mid+1;
            }else{
                r-=1;
            }
        }
        return ans;
    }
};
// @lc code=end