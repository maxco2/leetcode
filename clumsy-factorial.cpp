//
// @lc app=leetcode.cn id=162555475 lang=cpp
//
// [162555475] clumsy-factorial [笨阶乘]
//
class Solution {
public:
    int clumsy(int N) {
        int res=N--;
        int step=0;
        for(;N>=1;step++)
        {
            switch(step%4)
            {
                case 0:
                    //printf("*%d",N);
                    res*=N--;
                    break;
                case 1:
                    //printf("/%d",N);
                    res/=N--;
                    break;
                case 2:
                    //printf("+%d",N);
                    res+=N--;
                    break;
                case 3:
                    int step2=0;
                    //printf("-%d",N);
                    int tmpres=N--;
                    if(N>=1){
                        //printf("*%d",N);
                        tmpres*=N--;
                        if(N>=1){
                            //printf("/%d",N);
                            tmpres/=N--;
                        }
                    }
                    res-=tmpres;
                    step=1;
                    break;
            }
        }
        return res;

    }
};
// @lc code=end