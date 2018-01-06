class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for(int i = 0, j; i < words.size(); i = j) {
            int width = 0;
            for(j = i; j < words.size() && width + words[j].size() + j - i <= maxWidth; j++) {//找到每行应插入的j-i个单词
                width += words[j].size();
            }
            int space = 1, extra = 0;
            if(j - i != 1 && j != words.size()) {//这行不止一个单词且不是最后一行
                space = (maxWidth - width) / (j - i - 1);//每个间隔插入space个空格
                extra = (maxWidth - width) % (j - i - 1);//前extra个间隔需要额外插入一个空格
            }
            string line(words[i]);
            for(int k = i + 1; k < j; k++) {
                line += string(space, ' ');
                if(extra-- > 0) {
                    line += " ";
                }
                line += words[k];
            }
            
            line += string(maxWidth - line.size(), ' ');//补齐一行
            result.push_back(line);
        }
        return result;
    }
};