//
// @lc app=leetcode.cn id=169696910 lang=cpp
//
// [169696910] plus-one [加一]
//
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        reverse(digits.begin(),digits.end());
        bool c=false;
        if(digits[0]==9){
            c=true;
            ret.push_back(0);
        }else{
            ret.push_back(digits[0]+1);
        }
        for(int i=1;i<digits.size();++i){
            if(c){
                if(digits[i]==9){
                    ret.push_back(0);
                }else{
                    ret.push_back(digits[i]+1);
                    c=false;
                }
            }else{
                ret.push_back(digits[i]);
            }
        }
        if(c) ret.push_back(1);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end