//
// Created by yxr on 2018/8/10.
//
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left=0;
        int right=n;
        int mid=left+(right-left)/2;
        int g=guess(mid);
        while(g!=0){
            g=guess(mid);
            cout<<mid<<endl;
            cout<<g<<endl;
            if(g==-1){
                right=left+(right-left)/2;
            }
            if(g==1){
                left=left+(right-left)/2+1;
            }
            if(g==0){
                return mid;
            }
            mid=left+(right-left)/2;
        }
        return mid;
    }
};
