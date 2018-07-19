//
// Created by yxr on 2018/7/20.
//
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string path="";
        dfs(0, path, s, 4);
        return result;
    }
private:
    vector<string> result;
    void dfs(int c, string path, string s, int num){
        if(num<0)return;
        if(c==s.size() && num==0){
            result.push_back(path);
        }
        for(int i=c; i<s.size(); i++){
            if(is_valid(s, c, i+1))
            {
                string ip=s.substr(c, i-c+1);

                // int n=0;
                // for(int j=0;j<ip.size();j++){
                //     n=n*10+(ip[j]-'0');
                // }
                // if(n>255 || n<0)continue;

                if(path!="")
                    dfs(i+1, path+"."+ip, s, num-1);
                else
                    dfs(i+1, path+ip, s, num-1);
            }
        }

    }
    bool is_valid(string s, int start, int end){
        int num=0;

        if(end-start>3)return false;
        if(s[start]=='0' && end-start>1)return false;
        cout<<s.substr(start, end-start)<<endl;
        for(int i=start; i<end; i++){
            num=num*10+ (s[i] -'0');
        }
        cout<<num<<endl;
        if(0 <= num && num <= 255) return true;
        else return false;


    }
};
