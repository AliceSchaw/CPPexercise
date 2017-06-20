//6 ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return "";
        string res=strs[0];
        int idx;
        for(int i=1;i<strs.size();i++){
            
            if (res.size() == 0 || strs[i].size() == 0)  
                   return "";  
            
            //for (idx = 0; idx < strs[i].size(); ++idx)
            int len=res.length()<strs[i].length()?res.length():strs[i].length();
            for (idx = 0; idx < len; ++idx)  
            {  
               if (res[idx] != strs[i][idx])
                  break;  
            }  
            
            res = res.substr(0,idx);
            
        }
        return res;
    }
};