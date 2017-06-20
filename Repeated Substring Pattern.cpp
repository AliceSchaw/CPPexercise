//39ms
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string nextStr=s;
        if(s.empty())
            return true;
        for(int i=1;i<=s.size()/2;i++){
            if(s.size()%i==0){
                nextStr=leftstr(s,i);
                //cout<<s<<i<<endl;
                if(nextStr==s)  
                    return true;
            }
        }
        return false;

    }
    string leftstr(string &str,int l){
        string ret = str.substr(l);
        //cout<<ret<<endl;
        ret += str.substr(0, l);
        return ret;
    }
};