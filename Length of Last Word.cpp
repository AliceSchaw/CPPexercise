class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char> res;
        for(int i=0;i<s.length();i++){
            res.push(s[i]);
        }
        int num=0;
        while(!res.empty()){
            if(res.top()!=' '){num++;res.pop();}
            else if(res.top()==' '&&num==0){res.pop();}
            else return num;
        }
        return num;
    }
};