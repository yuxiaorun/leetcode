//
// Created by yxr on 2018/7/20.
//

class Solution(object):
def containsNearbyDuplicate(self, nums, k):
"""
:type nums: List[int]
:type k: int
:rtype: bool
"""
    d={}
    for i in range(len(nums)):
        if d.has_key(nums[i]):
            m=i-d[nums[i]]
            if m<=k:
                return True
             else:
                d[nums[i]]=i
        else:
            d[nums[i]]=i
    return False