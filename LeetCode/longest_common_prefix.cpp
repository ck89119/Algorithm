class Solution {
public:
    int min(int a, int b) {
      if (a < b) return a;
      else return b;
    }

    string longestCommonPrefix(vector<string> &strs) {
      if (strs.size() == 0) return "";
      int i, l, r;
      r = 999999;
      for (i = 0; i < strs.size(); ++i)
        r = min(r, strs[i].size());
      l = 0; ++r;
      while (l + 1 < r) {
        int mid = (l+r) >> 1;
        string prefix = strs[0].substr(0, mid);
        int flag = 1;
        for (i = 1; i < strs.size(); ++i)
          if (prefix != strs[i].substr(0, mid)) {
            flag = 0;
            break;
          }
        if (flag) l = mid;
        else r = mid;
      }
      return strs[0].substr(0, l);
    }
};
