//
// Created by yxr on 2018/7/22.
//
class Solution(object):
    def singleNumber(self, nums):
"""
:type nums: List[int]
:rtype: int
"""
        return sum(set(nums))*2-sum(nums)
