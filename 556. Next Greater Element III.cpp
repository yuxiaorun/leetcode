//
// Created by yxr on 2018/8/9.
//
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n!=0){
            digits.push_back(n%10);
            n=n/10;
        }
        reverse(digits.begin(), digits.end());
        int i=digits.size()-1;
        for(; i>0;i--){
            if(digits[i-1]<digits[i])break;
        }
        if(i==0)return -1;
        i--;
        int index=0;
        int value=INT_MAX;
        for(int j=digits.size()-1;j>i;j--){
            if(digits[j]>digits[i] && digits[j]<value){
                value=digits[j];
                index=j;
            }
        }
        int t=digits[i];
        digits[i]=digits[index];
        digits[index]=t;
        sort(digits.begin()+i+1, digits.end());
        double result=0;
        for(int i=0;i<digits.size();i++){
            result=result*10+digits[i];
        }
        cout<<result<<endl;
        return result>INT_MAX?-1:int(result);
    }
};
