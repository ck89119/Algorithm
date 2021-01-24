#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> st;
      int n = s.size();
      int v[n];
      int i, j, k, ans;
      ans = 0;
      memset(v, 0, sizeof(v));
      for (i = 0; i < n; ++i) {
        if (s[i] == '(') 
          st.push(i);
        else if (!st.empty()) {
          int pre = st.top();
          st.pop();

          int len = i - pre + 1;
          if (pre) len += v[pre-1];
          ans = max(ans, len);
          v[i] = len;
        }
      }
      return ans;
    }
}
