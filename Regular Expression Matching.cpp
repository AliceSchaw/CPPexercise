// 85 ms
//recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
//16ms
//DP
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
                /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m=s.size(),n=p.size();
        std::vector<vector<bool> > f(m+1,vector<bool>(n+1,false));
        f[0][0]=true;
        for(int i=1;i<=m;i++)
        	f[i][0]=false;
        // p[0.., j - 3, j - 2, j - 1] matches empty ,if p[j - 1] is '*' and p[0..j - 3] matches empty

        for(int j=1;j<=n;j++)
        	f[0][j]=j>1&&'*'==p[j-1]&&f[0][j-2];
        for(int i=1;i<=m;i++)
        	for(int j=1;j<=n;j++)
        		if(p[j-1]!='*')
        			f[i][j]=f[i-1][j-1]&&(s[i-1]==p[j-1]||'.'==p[j-1]);
        		else
        			f[i][j]=f[i][j-2]||(s[i-1]==p[j-2]||'.'==p[j-2])&&f[i-1][j];
    	return f[m][n];
    }
};
//DP2
//6ms
/*
	a *	b a * b
a   T F T F F F
b 	F T	T F F F
a 	F F F T F T	  
b 	F F F F T T
		  	    T

	a *	b 
a   T F T
a 	F T T	
a 	F F T	  
b 	F F T
		  T	 

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};