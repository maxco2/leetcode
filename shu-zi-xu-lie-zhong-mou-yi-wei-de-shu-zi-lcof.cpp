//
// @lc app=leetcode.cn id=179641762 lang=cpp
//
// [179641762] shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof [数字序列中某一位的数字]
//
class Solution {
public:
    // 1*10
    // 2*90
    // 3*900
    int findNthDigit(int n) {
        if(n<=9) return n;
        n-=10;
        long long cur=2;
        long long ex=90;
        while(n>cur*ex){
            n-=cur*ex;
            cur+=1;
            ex*=10;
        }
        //cout<<"ex:"<<ex<<" cur:"<<cur<<endl;
        //cout<<"n:"<<n<<endl;
        auto x=(long long)(pow(10,cur-1))+n/cur;
        auto r=(cur-1-n%cur);
        //cout<<"x:"<<x<<endl;
        //cout<<"r:"<<r<<endl;
        int ret=0;
        for(int i=0;i<=r;++i){
            ret=x%10;
            x=x/10;
        }
        return ret;
    }
};
// @lc code=end