//
// @lc app=leetcode.cn id=193770551 lang=cpp
//
// [193770551] find-in-mountain-array [山脉数组中查找目标值]
//
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
int n;
    bool check1(int mid,MountainArray& mountainArr,bool& istop){
        int cur=mountainArr.get(mid);
        if(mid>0&&mid<n-1){
            int midl=mountainArr.get(mid-1);
            int midr=mountainArr.get(mid+1);
            if(midl<cur&&cur<midr){
                return false;
            }else if(midl>cur&&cur>midr){
                return true;
            }else if(cur>midl&&cur>midr){
                istop=true;
                
                return true;
            }
        }else if(mid==0){
            return false;
        }else{
            return true;
        }
        return false;
    }
    int topv;
    int first,last;
    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int l=0;
        int r=n-1;
        int ans=r;
        first=mountainArr.get(0);
        last=mountainArr.get(r);
        while(l<=r){
            int mid=l+r>>1;
            bool istop=false;
            auto res=check1(mid,mountainArr,istop);
            if(istop){
                ans=mid;break;
            }
            if(res) ans=mid,r=mid-1;
            else l=mid+1;
        }
        topv=mountainArr.get(ans);
        if(topv<target) return -1;
        if(topv==target) return ans;
        //cout<<topv<<endl;
        auto top=ans;
        l=0;
        r=top-1;
        ans=r;
        while(l<=r){
            int mid=l+r>>1;
            int midv=mountainArr.get(mid);
            if(midv==target) return mid;
            if(midv>=target) ans=mid,r=mid-1;
            else l=mid+1;
        }
        l=top+1;
        r=n-1;
        ans=r;
        while(l<=r){
            int mid=l+r>>1;
            //cout<<"mid"<<mid<<endl;
            int midv=mountainArr.get(mid);
            if(midv==target) return mid;
            if(midv<=target) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
// @lc code=end