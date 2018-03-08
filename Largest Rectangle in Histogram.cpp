//超时
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int res;
        int minheight=0;
        for(int i=0;i<heights.size();i++){
            minheight=i;
            for(int j=i;j<heights.size();j++){
                if(heights[j]<heights[minheight])
                    minheight=j;
                res=max(res,heights[minheight]*(j-i+1));
            }
        }
        return res;
    }
};
//维护一个高度递增的序列
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int max_size=0;
        int index=0;
        stack<int> s;

        while(index<heights.size())
        {
            if(s.size()==0||heights[s.top()]<=heights[index])
            {
                s.push(index);
                index++;
            }
            else
            {
                int top=s.top();
                s.pop();
                int cur_size=0;

                if(s.size()==0)
                {
                    cur_size=heights[top]*index;
                }
                else
                {
                    cur_size=heights[top]*(index-s.top()-1);
                }

                if(cur_size>max_size) max_size=cur_size;
            }
        }

        return max_size;
    }
};