//
// Created by yxr on 2018/7/15.
//
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> r;
        if(intervals.size()==0)return r;
        int s[intervals.size()];
        int e[intervals.size()];
        for(int i=0;i<intervals.size();i++){
            s[i]=intervals[i].start;
            e[i]=intervals[i].end;
        }
        sort(s,s+intervals.size());
        sort(e,e+intervals.size());
        int j=0;
        for(int i=0; i<intervals.size();i++){
            if (i == intervals.size() - 1 || s[i + 1] > e[i]) {
                r.push_back(Interval(s[j], e[i]));
                j = i + 1;
            }
        }
        return r;
    }
};
