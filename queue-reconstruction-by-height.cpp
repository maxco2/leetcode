//
// @lc app=leetcode.cn id=186994939 lang=cpp
//
// [186994939] queue-reconstruction-by-height [根据身高重建队列]
//
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& a,const auto& b){
            if(a[1]==b[1]&&a[1]==0){
                return a[0]<b[0];
            }
            if(a[1]==b[1]){
                return a[0]>b[0];
            }else{
                return a[1]<b[1];
            }
        });
        vector<vector<int>> ret;
        ret.push_back(people[0]);
        for(int i=1;i<people.size();++i){
            if(people[i][1]==0){
                ret.push_back(people[i]);
            }else{
                auto it=ret.begin();
                int front=people[i][1];
                int ch=people[i][0];
                int t=0;
                //printf("ch:%d,front:%d\n",ch,front);
                for(;it!=ret.end();++it){
                    if((*it)[0]>=ch){
                        t+=1;
                        if(t==front){
                            //cout<<"fuck"<<endl;

                            ++it;
                            ret.insert(it,people[i]);
                            break;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end