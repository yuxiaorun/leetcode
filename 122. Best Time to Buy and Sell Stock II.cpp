//
// Created by yxr on 2018/7/7.
////
int maxProfit(vector<int>& A) {
    int profit=0,mini=INT_MAX,maxi=0;
    if(A.size()<2)
        return 0;
    for(int i=0;i<A.size()-1;i++)
    {
        while(A[i]<A[i+1] && i<A.size()-1)
        {
            mini=min(A[i],mini,A[i+1]);
            maxi=max(maxi,A[i+1]);
            i++;
        }
        if(mini!=INT_MAX){ profit+=maxi-mini;   maxi=0;     mini=INT_MAX;  }
    }
    return profit;
}
