//
// Created by yxr on 2018/7/16.
//
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int  count[26];
        for(int i=0;i<26;i++)
            count[i]=0;
        for(int i=0;i<s.length();i++){
            count[s[i]%97]++;
        }
        stack<int> A;
        int counter[26];
        for(int i=0;i<26;i++){
            counter[i]=0;
        }
        bool instack[26];
        for(int i=0;i<26;i++)
            instack[i]=false;
        for(int i=0;i<s.length();i++){
            if(!instack[s[i]%97]){
                while(!A.empty()&&(s[i]%97<A.top()&&counter[A.top()]<count[A.top()])){
                    instack[A.top()]=false;
                    A.pop();
                }
                A.push(s[i]%97);
                instack[s[i]%97]=true;

            }
            counter[s[i]%97]++;
        }
        string x="";
        while(!A.empty()){
            string k="";
            k+=(char)(A.top()+97);
            x=k+x;
            A.pop();
        }
        return x;
    }
};
