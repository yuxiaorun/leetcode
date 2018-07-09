//
// Created by yxr on 2018/7/9.
//
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int map[26];
        int count=0;
        for(int i=0;i<26;i++)map[i]=0;
        for(int i=0;i<tasks.size();i++){
            map[tasks[i]-'A']+=1;
        }
        sort(map,map+26);
        int max_len=map[25]-1;
        int slots=max_len*n;
        for(int i=0;i<25;i++){
            cout<<map[i]<<endl;
            slots-=min(max_len,map[i]);
        }
        return slots>0?tasks.size()+slots:tasks.size();
    }

};
