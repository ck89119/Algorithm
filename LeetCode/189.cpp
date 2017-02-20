// class Solution {
//  public:
//   int reverse(vector<int> &nums, int l, int r) {
//     while (l < r) {
//       swap(nums[l], nums[r]);
//       ++l; --r;
//     }
//     return 0;
//   }

//   void rotate(vector<int>& nums, int k) {
//     int n = nums.size();
//     k %= n;
//     reverse(nums, 0, n-k-1);
//     reverse(nums, n-k, n-1);
//     reverse(nums, 0, n-1);
//   }
// };

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<bool> vis(n, false);
    k %= n;

    for (int i = 0; i < n; ++i) 
      if (!vis[i]) {
        int j = i;
        int next_j = (j - k + n) % n;
        int tmp = nums[j];
        vis[j] = true;
        while (!vis[next_j]) {
          nums[j] = nums[next_j];
          j = next_j;
          next_j = (j - k + n) % n;
          vis[j] = true;
        }
        nums[j] = tmp;
      }
  }
};
