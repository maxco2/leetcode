//
// @lc app=leetcode.cn id=178732233 lang=cpp
//
// [178732233] count-triplets-that-can-form-two-arrays-of-equal-xor [形成两个异或相等数组的三元组数目]
//
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int tmp=-1;
        int idx=0;
        unordered_map<int,vector<int>> mem;
        int ret=0;
        for(auto& n:arr){
            if(tmp==-1) tmp=n;
            else{
                tmp^=n;
                n=tmp;
            }
            //printf("xor[%d]=%d\n",idx,tmp);
            if(tmp==0&&idx!=0){
                ret+=(idx);
            }
            if(mem.count(tmp)){
                //printf("hit ");
                for(auto& ii:mem[tmp])
                {
                    
                    auto k=idx;
                    auto i=ii+1;
                    if(i<k)
                    ret+=(k-i);
                    //printf("k(%d)-i(%d)=%d\n",k,i,k-i);
                }

            }
            if(mem.count(tmp)){
                mem[tmp].push_back(idx);
            }
            else{
                vector<int> idxv;
                idxv.push_back(idx);
                mem.emplace(tmp,move(idxv));
            }
            idx++;
        }
        // arr[j-1]^arr[i-1]==arr[j-1]^arr[k] i<j<=k
        // => arr[i-1]==arr[k] i-1<k && k=>j>i  => i<k+1
        return ret;

    }
};
// @lc code=end