//
// Created by yxr on 2018/8/8.
//
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result=0;
        int number=0;
        int sign=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(s[i]=='+'){
                result+=sign*number;
                sign=1;
                number=0;
            }
            else if(s[i]=='-'){
                result+=sign*number;
                sign=-1;
                number=0;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                sign=1;
                number=0;
                result=0;
            }
            else if(s[i]==')'){
                result+=sign*number;
                number=0;
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
            }
            else{
                number=number*10+s[i]-'0';
            }
        }
        if(number != 0) result += sign * number;
        return result;
    }

};
