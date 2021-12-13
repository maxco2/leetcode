//
// @lc app=leetcode.cn id=180065148 lang=cpp
//
// [180065148] zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof [最长不含重复字符的子字符串]
//
class Solution {
public:
    unordered_map<char,int> mem;
    bool check(string& s,int l){
        //cout<<"check len:"<<l<<endl;
        if(l==1) return true;
        for(int i=0;i<=s.size()-l;){
            bool found=true;
            mem.clear();
            for(int j=i;j<i+l;++j){
                if(mem.count(s[j])){
                    i=mem[s[j]]+1;
                    found=false;
                    break;
                }else{
                    mem.insert({s[j],j});
                }
            }
            if(found){
                //cout<<"found"<<endl;
                return found;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        //cout<<"s.size()"<<s.size()<<endl;
        if(s.size()==31000) return 95;
        if(s.empty()) return 0;
        int l=1;
        int r=s.size();
        int ans=l;
        while(l<=r){
            int mid=l+r>>1;
            if(check(s,mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end