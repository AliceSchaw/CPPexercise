//位运算
//^按位“异或”运算符
/*
    void swap(int &a,int &b)
    {
        a=a^b;
        b=b^a;
        a=a^b;
    }
*/
class Solution {
public:
   int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        //labs()对long类型取绝对值
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 

    }

};