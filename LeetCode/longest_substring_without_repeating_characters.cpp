class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() == 0) return 0;
      int ans;
      int i, j, l, r, n, vis[26];
      ans = 0;
      n = s.size();
      l = 1;
      r = n + 1;
      while (l + 1 < r) {
        int mid = (l+r) >> 1;
        int flag = 0;
        for (i = 0; i + mid - 1 < n; ++i) {
          memset(vis, 0, sizeof(vis));
          int ff = 1;
          for (j = i; j <= i + mid - 1; ++j)
            if (vis[s[j]-'a'] == 0)
              vis[s[j]-'a'] = 1;
            else {
              ff = 0;
              break;
            }
          if (ff) {
            flag = 1;
            break;
          }
        }
        if (flag) l = mid;
        else r = mid;
      }
      return l;
    }
};
