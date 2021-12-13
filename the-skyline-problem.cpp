//
// @lc app=leetcode.cn id=195473357 lang=cpp
//
// [195473357] the-skyline-problem [天际线问题]
//
class Solution {
public:
    struct Axis{
        int x;
        bool left;
        int h;
        bool operator<(const Axis& that)const{
            return x<that.x;
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Axis> bounds;
        sort(buildings.begin(),buildings.end(),[](const auto& a,const auto &b){
            return a[2]==b[2]? a[0]<b[0]:a[2]<b[2];
        });
        int h=buildings[0][2];
        bounds.push_back({buildings[0][0],true,h});
        bounds.push_back({buildings[0][1],false,h});
        for(int i=1;i<buildings.size();++i){
            if(buildings[i][2]!=h){
                h=buildings[i][2];
                bounds.push_back({buildings[i][0],true,h});
                bounds.push_back({buildings[i][1],false,h});
            }else{
                if(buildings[i][0]<=bounds.back().x)
                    bounds.back().x=max(bounds.back().x,buildings[i][1]);
                else{
                    bounds.push_back({buildings[i][0],true,h});
                    bounds.push_back({buildings[i][1],false,h});
                }
            }
        }
        sort(bounds.begin(),bounds.end());
        map<int,int> mem;
        vector<vector<int>> ret;
        mem.insert({0,1}); // height is zero, cnt is one;
        for(auto &axis:bounds){
            int maxh;
            if(axis.left){
                mem[axis.h]++;
                maxh=mem.rbegin()->first;
            }else{
                if(--mem[axis.h]==0) mem.erase(axis.h);
                maxh=mem.rbegin()->first;
            }
            if(axis.h>=maxh){
                if(ret.size()&&ret.back()[0]==axis.x) 
                    ret.pop_back();
                ret.push_back({axis.x,maxh});
            }
        }
        return ret;
    }
};
// @lc code=end