 //KPM
//6ms
 class Solution {
  public:
     void getNext(vector<int> &next, string &needle) {
         int i = 0, j = -1;
         next[i] = j;
         while (i < needle.length() - 1) {
             while (j != -1 && needle[i] != needle[j]) 
                j = next[j];
             ++i; ++j;
             
             if (needle[i] == needle[j]) 
                next[i] = next[j]; 
           else next[i] = j;
         }
     }
     int strStr(string haystack, string needle) {
         if (haystack.empty()) 
            return needle.empty() ? 0 : -1;
         if (needle.empty()) 
            return 0;
         vector<int> next(needle.length() + 1);
         getNext(next, needle);
         int i = 0, j = 0;
         while (i != haystack.length()) {
             while (j != -1 && haystack[i] != needle[j]) 
                j = next[j];
             ++i; ++j;
             if (j == needle.length()) 
                return i - j;
         }
         return -1;
     }
 };


 //6ms
  class Solution {
  public:
     int strStr(string haystack, string needle) {
        int i=0,j=0;
        if(needle.empty()||haystack.empty()){
            if(needle.empty()) 
                return 0;
            else 
                return -1;
        }
        
        for(i,j;i<haystack.size()&&j<needle.size();){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                i=i-j+1;
                j=0;
            }
        }
        
        return j==needle.size()?i-j:-1;
     }
 };