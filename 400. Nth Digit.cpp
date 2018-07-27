//
// Created by yxr on 2018/7/27.
//
class Solution {
public:
    int findNthDigit(int n) {
        int powTen = 1;
        int m=9;
        while (n > m * powTen)
        {
            n -= m * powTen;
            m*=10;
            ++powTen;
        }
        //determine which number the digit in is
        int num = (n - 1) /powTen + pow(10, powTen - 1);
        string s = to_string(num);
        //return the digit we want
        return s[(n - 1) % powTen]- '0';

    }
};
