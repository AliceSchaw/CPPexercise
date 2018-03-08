class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = (i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]);
        }
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, tar = m+n-1;
        while ( j>=0 ) {//确认nums2的所有数已经插入nums1
            if ( i<0 || nums2[j] >= nums1[i] )
                nums1[tar--] = nums2[j--];
            else
                nums1[tar--] = nums1[i--]; 
        }
    }
};