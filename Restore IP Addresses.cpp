class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> ret;
        helper(s, ret, 0, "", 0);
        return ret;
    }

    void helper(string s, vector<string> &ret, int index, string current, int count) {
        
        if (count > 4) return;
        if (count == 4 && index == s.size()) { ret.push_back(current); return;}
        
        for(int i = 1; i < 4; i++) {
            if ((index + i) > s.size()) break;
            string temp = s.substr(index,i);
            if (((temp[0] == '0') && (temp.size() > 1)) || ((i == 3) && (stoi(temp) > 255))) continue;
            helper(s, ret, index+i, current + temp + (count == 3 ? "" : "."), count+1);
        }
    }
};