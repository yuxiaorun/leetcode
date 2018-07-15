//
// Created by yxr on 2018/7/15.
//
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(char* s, char* p){
        if(s=='\0' && p=='\0')return true;
        if(*(p+1)!='*'){
            if(*s==*p || (*p=='.' && *s!='\0' ))return isMatch(s+1,p+1);
            else return false;
        }else{
            while(*s==*p || (*p=='.' && *s!='\0')){
                if(isMatch(s,p+2))return true;
                s++;
            }
            return isMatch(s,p+2);
        }

    }
};
