//6ms
class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        string res="1";
        while(--n){
            string cur="";
            for(int i=0;i<res.size();i++){
                int count=1;
                while(i+1<res.size()&&res[i]==res[i+1]){
                    count++;
                    i++;
                }
                /*
                char ccount='0'+count;
                string scount(1, ccount);
                cur+=scount+res[i];
                */
                cur+=to_string(count)+res[i];
            }
            res=cur;
        }
        return res;
    }
};