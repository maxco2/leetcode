//
// @lc app=leetcode.cn id=177557899 lang=cpp
//
// [177557899] can-place-flowers [种花问题]
//
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(n){
            bool changed=false;
            while(i<flowerbed.size()){
                if(flowerbed[i]==1){
                    i+=2;
                }else{
                    bool cond=true; 
                    if(i-1>=0)
                     cond&=(flowerbed[i-1]==0);
                     if(i+1<flowerbed.size())
                     cond&=(flowerbed[i+1]==0);
                    if(cond){
                        n-=1;
                        flowerbed[i]=1;
                        changed=true;
                        i+=2;
                        break;
                    }else{
                        i+=1;
                    }
                }
            }
            if(!changed){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end