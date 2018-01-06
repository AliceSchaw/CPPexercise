//二分法
class Solution {
public:
    int mySqrt(int x) {
        int low = 0,  high = x, mid;
        if(x<0) return -1;  
        if(x<2) return x; // to avoid mid = 0
        while(low<high)
        {
            mid = (low + high)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return high-1;
        
    }
};
//牛顿法   yn+1=yn-f(yn)/f'(yn)
//令f(y)=y*y-x=0 =>f'(y)=2*y
//yn+1=yn-[(yn*yn-x)/2*yn]
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;  
        double lastY = 0;  
        double y = 1;  
        while (y != lastY)  
        {  
            lastY = y;  
            y = (y + x / y) / 2;  
        }  
        return (int)(y); 
        
    }
};