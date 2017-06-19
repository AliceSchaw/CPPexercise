//22ms
class Solution {
public:
    int reverse(int x) {
        //定义为long long防止溢出
        long long res=0;
        while(x/10!=0){
            res*=10;
            res+=x%10;
            x=x/10;
        }
        if(x%10!=0){
            res*=10;
            res+=x%10;
            
        }
        cout<<res<<endl;
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;

    }
    
};
//16ms
/*
class Solution {
public:
    int reverse(int x) {
        long long res=0;
        for(int i=0;x/10!=0;i++){
            res*=10;
            res+=x%10;
            x=x/10;
        }
        if(x%10!=0){
            res*=10;
            res+=x%10;
            
        }
        cout<<res<<endl;
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;

    }
    
};
*/