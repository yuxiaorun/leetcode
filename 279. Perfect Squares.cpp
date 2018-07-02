class Solution {
public:
    int numSquares(int n) {
        vector<int> record(n+1,INT_MAX);
        record[0]=0;
        for(int i=1;i*i<=n;i++){
            record[i*i]=1;
        }
        return helper(n, record);
    }
private:
    int helper(int n, vector<int>& record){
        if(record[n]!=INT_MAX)return record[n];
        int result=INT_MAX;
        for(int j=1;j*j<n;j++){
            result=min(result, helper(n-j*j, record)+1);
        }
        record[n]=result;
        return result;
        
    }
};
