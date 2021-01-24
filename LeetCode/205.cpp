class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    int n = s.size();
    vector<int> a(n), b(n);
    int val = 0;
    map<char, int> vis;
    for (int i = 0; i < n; ++i) {
      char ch = s[i];
      if (vis.find(ch) == vis.end())
        vis[ch] = val++;
      a[i] = vis[ch];
    }

    val = 0;
    vis.clear();
    for (int i = 0; i < n; ++i) {
      char ch = t[i];
      if (vis.find(ch) == vis.end())
        vis[ch] = val++;
      b[i] = vis[ch];
    }

    for (int i = 0; i < n; ++i)
      if (a[i] != b[i]) return false;
    return true;
  }
};
