class Solution {
    public:
        bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        unordered_map<char,int> strmap;
        int length=s1.size();
        for(int i=0;i<length;i++)
        {
            strmap[s1[i]]++;
            strmap[s2[i]]--;
        }
        for(int i=0;i<length;i++)
        {
            if(strmap[s1[i]]!=0 )
            return false;
        }
        for(int i=1;i<length;i++)
        {
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble( s1.substr(i),s2.substr(i) )  )
            return true;
            if(isScramble( s1.substr(0,i),s2.substr(length-i) ) && isScramble( s1.substr(i),s2.substr(0,length-i) )  )
            return true;
        }
        return false;
        }
};