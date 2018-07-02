class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map <char,char> match;
        match['{']='}';
        match['(']=')';
        match['[']=']';
        char t;
        const char* c=s.c_str();
        while(*c!='\0'){
            if(match.find(*c)!=match.end()){
                st.push(*c);
            }
            else if(!st.empty() && match[st.top()]==*c){
                st.pop();
            }
            else return false;
            cout<<*c<<endl;
            c++;
        }
        return st.empty();
    }
};