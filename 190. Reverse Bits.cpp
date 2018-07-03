//
// Created by yxr on 2018/7/3.
//

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t r = 0;
        uint32_t mask = 1;
        int bitsmove = 31;

        //half rightside
        while (bitsmove > 0)
        {
            r += (n & mask) << bitsmove;
            bitsmove -= 2;
            mask *= 2;
        }
        //half leftside
        bitsmove = 1;
        while (bitsmove <= 31)
        {
            r += (n & mask) >> bitsmove;
            bitsmove += 2;
            mask *= 2;
        }
        return r;
    }
};