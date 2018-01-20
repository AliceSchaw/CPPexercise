class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		if (k == 0 || n == k) {
            for (int i = 1; i <= k; ++i)
                p[i - 1] = i;
            result.push_back(p);
            return result;
        }
        //n==k的情况需要多执行n(n-1)/2次

		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};

//C(n,k)=C(n-1,k-1)+C(n-1,k)
class Solution {
public:
	 vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res,res1;
       
        if(k==n || k==0)
        {
            vector<vector<int> > res2;
            vector<int> curr;
            for(int i=1;i<=k;i++)
                curr.push_back(i);
            res2.push_back(curr);
            return res2;
        }
        
        res = combine(n-1,k-1);
        
        for(auto itr=res.begin();itr!=res.end();itr++)
        {
            itr->push_back(n);
        }
        
        res1 = combine(n-1,k);
        
        res.insert(res.end(),res1.begin(),res1.end());
        return res;
    }
};
