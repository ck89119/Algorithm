class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int sum = 0;
      int i, j;
      int n = nums.size();
      int ans = (1 << 31) - 1;
      i = j = 0;
      while (i < n) {
        while (sum < s && j < n) {
          sum += nums[j];
          ++j;
        }
        if (sum >= s)
          ans = min(ans, j - i); 
        sum -= nums[i];
        ++i;
      }
      if (ans == (1 << 31) - 1) 
        ans = 0;
      return ans;
    }
};
