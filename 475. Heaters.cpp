//
// Created by yxr on 2018/7/30.
//
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m=0;
        int j=0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int i=0;i<houses.size();i++){
            int p=houses[i];
            int d=INT_MAX;
            while(j<heaters.size()-1 && heaters[j]<p){
                j++;
            }

            d=min(abs(heaters[j]-p),d);

            if(j>0)d=min(p-heaters[j-1],d);
            m=max(m, d);
        }
        return m;
    }
};
