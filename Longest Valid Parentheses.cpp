//error：()(()情形会输出错误结果4
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> res;
        int count=0,maxl=0;
        for(int i=0;i<s.size();i++){
            //特殊情形：()(),()(()
            if(s[i]=='('){
                res.push(s[i]);
            }
            
            if(s[i]==')'){
                if(res.empty())
                    maxl=max(count,maxl);
                    count=0;
                else{
                    res.pop();
                    count++;
                } 
            }
        }
        maxl=max(count,maxl);
        return 2*maxl;
    }
};
*/

//6ms
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) 
            longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); 
                st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};