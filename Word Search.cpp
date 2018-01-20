class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
       m=board.size();  
       n=board[0].size();
       for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
        {
            if(isFound(board,word,0,x,y))//if(isFound(board,word.c_str(),x,y))
                return true;
        }
        return false;
    }
private:
    int m;
    int n;
    bool isFound(vector<vector<char> > &board, string word,int w, int x, int y)//bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
    {
        if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||word[w]!=board[x][y])
            return false;
        if(word[w+1]=='\0')
            return true;
        char t=board[x][y];
        board[x][y]='\0';
        if(isFound(board,word,w+1,x-1,y)||isFound(board,word,w+1,x+1,y)||isFound(board,word,w+1,x,y-1)||isFound(board,word,w+1,x,y+1))
            return true; 
        board[x][y]=t;
        return false;
    }
};