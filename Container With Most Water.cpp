//19ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),res=0;
        int left=0,right=n-1;
        while(left<right){
            res=max(res,min(height[left],height[right])*(right-left));
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return res;
    }
};