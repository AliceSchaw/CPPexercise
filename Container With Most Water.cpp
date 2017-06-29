//19ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),res=0;
        int left=0,right=n-1;
        while(left<right){
            res=max(res,min(height[left],height[right])*(right-left));
            if(height[left]>height[right])
                //提高短板才有可能使面积更大
                right--;
            else
                left++;
        }
        return res;
    }
};