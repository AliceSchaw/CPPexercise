class Solution {
public:
    int numDecodings(string s) {
     int n = s.size();
        if(n == 0 || s[0] == '0') return 0;
        if(n == 1) return 1;
        int res = 0,fn_1 = 1,fn_2 = 1;
        for(int i = 1;i < n;i++){
            int temp = fn_1;
            if(isValid(s[i])&&isValid(s[i-1],s[i]))  res+=fn_1+fn_2;
            else if(!isValid(s[i])&&isValid(s[i-1],s[i])) res+=fn_2;
            else if(isValid(s[i])&&!isValid(s[i-1],s[i])) res+=fn_1;
            else if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
            fn_1 = res;
            fn_2 = temp;
            res = 0;
        }
        return fn_1;
    
    }
    bool isValid(char a,char b){
        return a == '1'||(a == '2' && b <='6');
    }
    bool isValid(char a){
        return a != '0';
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if ( n == 0 || s[0] == '0' ) return 0;
        if ( n == 1 ) return 1;
        int m1 = 1, m2 = 1, num;
        for ( int i = 1; i < n; i++ ) {
            num = 0;
            if ( !isValid(s[i]) && !isValid(s[i-1], s[i]) ) return 0;//00无效
            if ( isValid(s[i]) ) num = m1;//res[i]=res[i-1]
            if ( isValid(s[i-1], s[i]) ) num += m2;//res[i]=res[i-2]+res[i-1]||res[i]=res[i-2]
            m2 = m1;//m2=res[i-2]
            m1 = num;//m1=res[i-1]
        }
        return num;
    }
    bool isValid(char a,char b){
        return a == '1'||(a == '2' && b <='6');
    }
    bool isValid(char a){
        return a != '0';
    }
};