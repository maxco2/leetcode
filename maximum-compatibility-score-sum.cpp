//
// @lc app=leetcode.cn id=199527574 lang=cpp
//
// [199527574] maximum-compatibility-score-sum [最大兼容性评分和]
//
class Solution {
public:
    using ui = unsigned int;
    vector<ui> to_vec(vector<vector<int>>& students){
        vector<ui> stds;
        for(auto & v:students){
            ui tmp=0;
            for(int i=0;i<v.size();++i){
                if(v[i]==1)
                tmp+=(1<<(v.size()-i-1));
            }
            stds.push_back(tmp);
            //cout<<tmp<<endl;
        }
        return stds;
    }
    int cnt(unsigned int n)
    {
        int c=0;
        for(int i=0;i<k;++i){
            c+=((n&1)^1);
            n>>=1;
        }
        return c ;
    }
    int k;
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        auto s=to_vec(students);
        auto m=to_vec(mentors);
        k=mentors[0].size();
        sort(s.begin(),s.end());
        int res=0;
        do{
            int tmp=0;
            for(int i=0;i<m.size();++i){
                auto r=s[i]^m[i];
                tmp+=cnt(r);
            }
            res=max(res,tmp);
        }while(next_permutation(s.begin(),s.end()));
        return res;
    }
};
// @lc code=end