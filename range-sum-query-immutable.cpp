//
// @lc app=leetcode.cn id=168789710 lang=cpp
//
// [168789710] range-sum-query-immutable [区域和检索 - 数组不可变]
//
class NumArray {
public:
    int* bit;
    int lowbit(int x){return x&(-x);}
    
    NumArray(vector<int> nums) {
        auto sz=nums.size();
        //bit=vector<int>(sz+1,0);
        bit=new int[sz+1];
        for(int i=1;i<sz+1;++i)
        {
            bit[i] = nums[i - 1];
            for (int j = i - 2; j >= i - lowbit(i); j--)
                bit[i] += nums[j];
        }
    }
    
    int sum (int k)
    {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        ans += bit[i];
    return ans;
    }

    
    int sumRange(int i, int j) {
        if(i==0) return sum(j+1);
        return sum(j+1)-sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
// @lc code=end