//3ms
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        addingpar(result,"",n,0);
        return result;

    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }

};