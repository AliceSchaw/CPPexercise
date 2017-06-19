class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;

        long long res=0;
        int sour=x;
        while(x/10){
            res*=10;
            res+=x%10;
            x=x/10;
        }
        if(x%10!=0){
            res*=10;
            res+=x%10;
            
        }
        if(res==sour){
        	return (res<INT_MIN || res>INT_MAX) ? false : true;
        }
        return false;
    }
};