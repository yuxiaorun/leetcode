class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)return 1;
        if(n==1)return x;
        if(n==0)return 1;
        if(n<0){
            x = 1/x;
            return (n %2 == 0) ? myPow(x*x, -(n/2)) : x*myPow(x*x, -(n/2));
        }
        if(n%2==0){
            double x2=myPow(x,n/2);
            return x2*x2;
        }else{
            double x2=myPow(x,n/2);
            return x2*x2*x;
        }


    }
};