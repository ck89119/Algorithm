class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n = nums.size();
      vector<bool> vis(n, false);
      while (1) {
        int flag = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
          while (i < j && vis[i]) ++i;
          while (i < j && vis[j]) --j;
          while (i < j && nums[i] == nums[j]) ++i;
          if (i < j) {
            vis[i] = vis[j] = true;
            flag = 1;
          }
          ++i; --j;
        }
        if (flag == 0) break;
      }

      int ans = 0;
      for (int i = 0; i < n; ++i)
        if (!vis[i]) {
          ans = nums[i];
          break;
        }
      return ans;
    }
};
