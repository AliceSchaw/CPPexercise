//16ms
class Solution {
public:
    int myAtoi(string str) {
        int sign=1;
        bool isset=false;
        int i=0;
        if(str.empty()){
            return 0;
        }
        while(i<str.size()){
            if(str[i]!=' '){
                break;
            }
            i++;
            
        }
        if(str[i]=='+'){
            //双引号代表字符串，自带/0
            if(isset){
                return 0;
            }
            sign=1;
            i++;
            isset=true;
        }
        if(str[i]=='-'){
            if(isset){
                return 0;
            }
            sign=-1;
            i++;
            isset=true;
        }
        int result=0;
        for(i;i<str.size();i++){
        
            if (str[i] < '0' || str[i] > '9'){
                break;
            }
            // overflow
            if (result * sign > INT32_MAX / 10 ||
                (result * sign == INT32_MAX / 10 && (str[i] - '0') > INT32_MAX % 10)){
                return INT32_MAX;
            }
            if (result * sign < INT32_MIN / 10 ||
                (result * sign == INT32_MIN / 10 && (str[i] - '0') * sign < INT32_MIN % 10)){
                return INT32_MIN;
            }
            result=result*10+str[i]-'0';
        }
        return sign*result;
    }
};