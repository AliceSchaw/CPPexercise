// 3 ms
class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='('){
                res.push(s[i]);
            }
            
            switch(s[i]){
                case ')':
                if(res.empty() || res.top()!='(')
                    return false;
                else 
                    res.pop();
                break;
                case ']':
                if(res.empty() || res.top()!='[')
                    return false;
                else
                    res.pop();
                break;
                case '}':
                if(res.empty() ||res.top()!='{')
                    return false;
                else 
                    res.pop();
                break;
            }

        }
        /*if(res.size()==0)
            return true;
        else 
            return false;*/
        return res.empty() ;
    }
};