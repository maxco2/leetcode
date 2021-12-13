#
# @lc app=leetcode.cn id=213834045 lang=python3
#
# [213834045] compare-version-numbers [比较版本号]
#
class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        l1=v1.split('.')
        l2=v2.split('.')
        if len(l1)>len(l2):
            return -self.compareVersion(v2,v1)
       
        for i in range(0,len(l1)):
            if int(l1[i])>int(l2[i]):
                return 1
            elif int(l1[i])<int(l2[i]):
                return -1
        
        for i in range(len(l1),len(l2)):
            if int(l2[i])>0:
                return -1
        return 0
# @lc code=end