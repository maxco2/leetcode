//
// @lc app=leetcode.cn id=194101867 lang=cpp
//
// [194101867] time-based-key-value-store [基于时间的键值存储]
//
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string,vector<pair<int,string>>> mem;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        auto& v=mem[key];
        {
            v.emplace_back(pair<int,string>{timestamp,value});
        }
        //mem[key].insert(it,{timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mem.count(key)){
            auto& v=mem[key];
            int l=0;
            int r=v.size()-1;
            int ans=r;
            while(l<=r){
                int mid=l+r>>1;
                if(v[mid].first<=timestamp) ans=mid,l=mid+1;
                else r=mid-1;
            }
            if(v[ans].first<=timestamp){
                return v[ans].second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end