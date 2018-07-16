//
// Created by yxr on 2018/7/16.
//
class Solution {
public:
    static bool cmp(pair<int, int>a, pair<int, int>b)
    {
        return a.first<b.first;//根据fisrt的值升序排序
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int p_size=people.size();
        vector<pair<int,int>> r(p_size, make_pair(-1,0));

        sort(people.begin(),people.end(), cmp);
        vector<int> to_delete;
        for(int i=0;i<p_size;i++){
            int index=people[i].second;
            cout<<people[i].first<<' ';
            int j=0;
            while(index>0){
                if(r[j].first==-1 || r[j].first==people[i].first){
                    j++;
                    index--;
                }else{
                    j++;
                }
            }
            while(r[j].first!=-1)j++;
            cout<<j<<endl;
            r[j]=people[i];
        }
        return r;
    }
};
