//
// Created by yxr on 2018/7/7.
//
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        string s(10, '0');
        dfs(0, num, s);
        return result;
    }
private:
    vector<string> result;
    void dfs(int step, int left, string s){
        if(10 - step<left)return;
        if(step==10 && left==0){
            string r=translate(s);
            if(r!="0")
                result.push_back(translate(s));
            return;
        }

        if(left>0){
            s[step] = '1';
            dfs(step + 1, left - 1, s);
            s[step] = '0';
        }
        dfs(step+1, left, s);

    }
    string translate(string light){
        int hour = 0;
        for(int i=0; i<4; i++){
            if(light[i] == '1')hour +=pow(2,i);
        }
        if(hour>11)return "0";
        int minute = 0;
        for(int i = 4; i < 10; i++){
            if(light[i] == '1')minute+=pow(2,i-4);
        }
        if(minute>59)return "0";
        string shour=to_string(hour);

        string sminute=to_string(minute);
        if(sminute.size()==1)sminute="0"+sminute;
        return shour+":"+sminute;
    }
};
