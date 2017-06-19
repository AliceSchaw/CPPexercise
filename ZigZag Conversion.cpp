//29ms
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
        return s;
        string *str = new string[numRows];
        int res=0,step=1;
        for(int i=0;i<s.size();i++){
            if (res == 0)
                step = 1;
            else if (res == numRows - 1)
                step = -1;
            str[res].push_back(s[i]);
            res+=step;
        }
        s.clear();
        for (int j = 0; j < numRows; ++j)
        {
            s.append(str[j]);
        }

        delete[] str;
        return s;
        
    }
};