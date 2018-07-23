class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<vector<int>> ABCD(4, vector<int>(0));
        unordered_map<int,int> record;
        int result=0;
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++)record[C[i]+D[j]]+=1;
        }
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                result += record[-(A[i]+B[j])];
            }
        }
        return result;
    }

};//
// Created by yxr on 2018/7/23.
//

