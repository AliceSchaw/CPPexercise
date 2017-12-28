//9ms
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            //n=-n越界
            if( n == INT_MIN)
            {
                ++n;
                n = -n;
                x = 1/x;
                return x * x * pow( x*x, n/2 );
            }
            /*
            if( n == INT_MIN)
            {
                n+=2;
            }
            */
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
};
