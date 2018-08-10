//
// Created by yxr on 2018/8/10.
//
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(auto it=tokens.begin(); it != tokens.end(); it++){
            if(isOPT(*it)){
                int b=numbers.top();
                numbers.pop();
                int a= numbers.top();
                numbers.pop();
                int c=calculate(a,b,*it);
                numbers.push(c);
            }else{

                int i=atoi((*it).c_str());
                numbers.push(i);
            }

        }
        return numbers.top();
    }
private:
    bool isOPT(string s){
        if(s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        return false;
    }
    int calculate(int a, int b, string opt){
        switch(opt[0]){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
        }
    }
};
