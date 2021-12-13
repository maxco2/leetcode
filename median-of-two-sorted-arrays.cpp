//
// @lc app=leetcode.cn id=177949463 lang=cpp
//
// [177949463] median-of-two-sorted-arrays [寻找两个正序数组的中位数]
//
enum {
    ML=1, // move left
    MR=2, //move right
};
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            auto len1=nums1.size();
            auto len2=nums2.size();
            if(len1==0||len2==0){
                return len1==0?(nums2[len2>>1]+nums2[len2-1>>1])/2.0:(nums1[len1>>1]+nums1[len1-1>>1])/2.0;
            }
            if(len1>len2){
                swap(nums1,nums2);
                len1=nums1.size();
                len2=nums2.size();
            }
            int l=0;
            int r=len1;
            int ans=l;
            double res=0.0;
            bool b=false;
            auto  check=[&nums1,&nums2,len1,len2,&res](int mid){
                int n =(len1+len2+1)/2-mid;
                int m_1=mid-1;
                int m = mid;
                int n_1 = n-1;
                bool odd=(len1+len2)%2==1;
                if(m==0){
                    if(odd){
                        res= nums2[n_1];
                    }else{
                        if(n<len2)
                            res=(nums2[n_1]+min(nums2[n],nums1[m]))/2.0;
                        else
                            res=(nums2[n_1]+nums1[m])/2.0;
                    }
                    return nums2[n_1]<=nums1[m]?MR:-MR;
                }
                if(m==len1){
                    if(odd){
                        if(n_1>=0)
                            res=max(nums1[m_1],nums2[n_1]);
                        else
                            res=nums1[m_1];
                    }else{
                        int left;
                        if(n_1>=0)
                            left = max(nums1[m_1],nums2[n_1]);
                        else
                            left=nums1[m_1];
                        int right=nums2[n];
                        res=(left+right)/2.0;
                    }
                    return nums1[m_1]<=nums2[n]?ML:-ML;
                }

                int left = max(nums1[m_1],nums2[n_1]);
                int right = min(nums2[n],nums1[m]);
                if(!odd)
                    res=(left+right)/2.0;
                else{
                    res=left;
                }
                bool b1=nums1[m_1]<=nums2[n];
                bool b2=nums2[n_1]<=nums1[m];
                if(b1&&b2)
                {
                    return 3;
                }
                if(!b1){
                    return -ML;
                }
                if(!b2){
                    return -MR;
                }
                return 3;
            };
            while(l<=r)
            {
                int mid=l+r>>1;
                int p=check(mid);
                if(p>0) {
                    ans=mid;
                    break;
                }

                p=p*-1;
                if(p==ML){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            //check(ans);
            return res;
        }
};

// @lc code=end