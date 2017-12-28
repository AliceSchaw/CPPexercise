//29ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        /*
        for(int i=0;i<strs.size();i++) {
            string t = strs[i]; 
            sort(t.begin(), t.end());
            mp[t].insert(strs[i]);
        }
        */
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        /*
        for (map<string,multiset<string>>::iterator it=mp.begin(); it!=mp.end(); it++)  
        {  
            vector<string> anagram(it->second.begin(),it->second.end());
            anagrams.push_back(anagram);
        } 
        */
        return anagrams;
    }
};
//36ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        unordered_map<string, vector<string>> count;
        int i = 0;
        for (auto s : strs)
        {
            sort(s.begin(), s.end());
            count[s].push_back(strs[i++]);
        }
        vector<vector<string>> res;
        for (auto n : count){
            sort(n.second.begin(), n.second.end());
            res.push_back(n.second);
        }
        return res;
    }
};
//55ms
//Map中的元素是自动按key升序排序
class Solution {  
public:  
    vector<vector<string>> groupAnagrams(vector<string>& strs) {  
        vector<vector<string>> result;  
        map<string, vector<string>> codeToStrs;

        for(int i = 0; i<strs.size(); i++){  
            codeToStrs[getsortCode(strs[i])].push_back(strs[i]);  
        }  
          
        for(map<string, vector<string>>::iterator it = codeToStrs.begin(); it!= codeToStrs.end(); it++){  
            result.push_back(it->second);  
        }  
          
        return result;  
    }  
      
    string getsortCode(string s){  
        sort(s.begin(), s.end());  
        return s;  
    }  
};  