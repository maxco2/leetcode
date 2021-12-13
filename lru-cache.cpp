//
// @lc app=leetcode.cn id=196009756 lang=cpp
//
// [196009756] lru-cache [LRU 缓存机制]
//
class LRUCache {
public:
    
    static const int N=2e5+10;
    struct KV{
        int key,value;
    }e[N];
    int l[N],r[N],h[N],idx;
    int size;
    int capacity;
    unordered_map<int,int> mem;
    LRUCache(int _capacity) {
        r[0]=1;
        l[1]=0;
        idx=2;
        size=0;
        capacity=_capacity;
    }
    
    int get(int key) {
        if(!mem.count(key)){
            return -1;
        }else{
            auto p=mem[key];
            remove(p);
            add(0,e[p].key,e[p].value);
            mem[key]=idx-1;
            return e[p].value;
        }
    }
    
    void add(int k,int key,int value){
        e[idx].key=key;
        e[idx].value=value;
        r[idx]=r[k];
        l[r[k]]=idx;
        r[k]=idx;
        l[idx]=k;
        idx++;
    }
    void remove(int k){
        r[l[k]]=r[k];
        l[r[k]]=l[k];
    }
    void put(int key, int value) {
        if(!mem.count(key)){
            add(0,key,value);
            mem[key]=idx-1;
            size++;
            if(size>capacity){
                auto tk=e[l[1]].key;
                remove(l[1]);
                mem.erase(tk);
                size-=1;
            }
        }else{
            auto p=mem[key];
            remove(p);
            add(0,key,value);
            mem[key]=idx-1;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end