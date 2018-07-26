//
// Created by yxr on 2018/7/26.
//
class Solution {
public:
    int romanToInt(string s) {
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int num[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        char* p=&s[0];
        int result=0;
        for(int i=0;i<13;i++){
            while(*p!='\0' && isMatch(p,symbol[i])){
                result+=num[i];
                cout<<num[i]<<endl;
                p++;
                if(symbol[i].size()==2)p++;
            }
        }
        return result;
    }
private:
    bool isMatch(char* p,string s){
        if(s.size()>1){
            return *p==s[0] && *(p+1)==s[1];}
        else{
            return *p==s[0];
        }
    }
};
