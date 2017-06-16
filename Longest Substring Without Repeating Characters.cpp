class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //char最大值为127
        //char res[255]={0};
        //memset(res,-1,255);
        vector<int> res(256, -1);

        
        int maxLen=0,start=-1;
        for(int i=0;i<s.length();i++){
            if(res[s[i]]>start)
                start=res[s[i]];
            res[s[i]]=i;
            maxLen=max(maxLen,i-start);
            cout<<i<<","<<start<<","<<maxLen<<endl;
        }
        return maxLen;
    }
};