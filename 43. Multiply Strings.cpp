//
// Created by yxr on 2018/7/18.
//
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        if(num1.size()>4 || num2.size()>4){
            string num11=num1.substr(0,num1.size()/2);
            string num12=num1.substr(num1.size()/2, num1.size()-num1.size()/2);
            string num21=num2.substr(0,num2.size()/2);
            string num22=num2.substr(num2.size()/2, num2.size()-num2.size()/2);
            string zero1=string(num1.size()-num1.size()/2,'0');

            string zero2=string(num2.size()-num2.size()/2, '0');
            cout<<num11<<endl;
            cout<<num21<<endl;
            string a1=add(multiply(num11, num21)+zero1+zero2,multiply(num11,num22)+zero1);
            string a2=add(multiply(num12, num21)+zero2, multiply(num12, num22));
            return add(a1,a2);
        }else{
            int a=atoi(num1.c_str());
            int b=atoi(num2.c_str());
            return to_string(a*b);
        }
    }
private:

    string add(string s1, string s2){
        if(s1.size()<s2.size()){
            string t=s1;
            s1=s2;
            s2=t;
        }
        int m=s1.size()-1;
        int n=s2.size()-1;
        int remain=0;
        string r="";
        while(m>-1){
            int i1=s1[m]-'0';
            int i2=n>-1?s2[n]-'0':0;
            int a=(i1+i2+remain)%10;
            remain=(i1+i2+remain)/10;
            r+='0'+a;
            m--;
            n--;
        }
        if(remain>0)r+='0'+remain;
        reverse(r.begin(), r.end());
        return r;
    }
};
