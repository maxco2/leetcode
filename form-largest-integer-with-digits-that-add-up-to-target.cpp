//
// @lc app=leetcode.cn id=186049930 lang=cpp
//
// [186049930] form-largest-integer-with-digits-that-add-up-to-target [数位成本和为目标值的最大数字]
//
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1,"0");
        dp[0]="";
        for(int i=1;i<10;++i)
            for(int j=cost[i-1];j<target+1;++j){    
                if(dp[j-cost[i-1]]!="0"){
                    dp[j]=cmps(dp[j],to_string(i)+dp[j-cost[i-1]]);
                }
            }
        return dp[target];
    }
private:
    string cmps(const string& s1,const string& s2){
        int m=s1.size(),n=s2.size();
        if(m==n)return max(s1,s2);
        return m>n?s1:s2;
    }
};
// @lc code=end