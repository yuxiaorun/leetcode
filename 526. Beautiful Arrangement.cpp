//
// Created by yxr on 2018/8/11.
//
class Solution {
public:
    int count=0;
    int countArrangement(int N) {
        vector<int> vs;
        for (int i=0; i<N; ++i) vs.push_back(i+1);
        counts(N, vs);
        return count;
    }
    void counts(int n, vector<int>& vs) {
        if (n <= 0){
            count++;
            return;
        }

        for (int i=0; i<n; ++i) {
            if (vs[i]%n==0 || n%vs[i]==0) {
                swap(vs[i], vs[n-1]);
                counts(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
    }
};
