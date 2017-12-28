//greedy
//12ms
class Solution {
public:
    int jump(vector<int>& nums) {
    int step = 0, curEnd = 0, curFarthest = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		curFarthest = max(curFarthest, i + nums[i]);
		if (i == curEnd) {
			step++;
			curEnd = curFarthest;
		}
	}
	return step;
    }
};
//DFS
//16ms
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++; 
			int maxend = end + 1;
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) 
                	return step;
				maxend = max(maxend, i + nums[i]);
			}
            start = end + 1;
            end = maxend;
        }
		return step;
    }
};