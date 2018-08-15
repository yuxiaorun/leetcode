//
// Created by yxr on 2018/8/15.
//
class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        bool remove=false;
        while(left<=right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                if(remove)break;
                else{
                    left++;
                    remove=true;
                }
            }
        }
        if(left>right)return true;
        left=0;
        right=s.size()-1;
        remove=false;
        while(left<=right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                if(remove)break;
                else{
                    right--;
                    remove=true;
                }
            }
        }
        if(left>right)return true;
        return false;
    }
};
