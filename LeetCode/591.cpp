#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  map<string, string> match;
  bool isTagNameValid(string tag_name) {
    if (tag_name.size() == 0 || tag_name.size() >= 10) return false;
    for (auto ch: tag_name) {
      if (ch < 'A' || ch > 'Z') return false;
    }
    return true;
  }

  int get_matched_pos(string pre, int pos, const string &code) {
    string matched_symbol = match[pre];
    int n = matched_symbol.size();
    for (int i = pos; i + n <= code.size(); ++i) {
      if (matched_symbol == code.substr(i, n)) return i;
    }
    return -1;
  }

  bool isValid(string code) {
    match["<"] = ">";
    match["</"] = ">";
    match["<![CDATA["] = "]]>";
    stack<string> tags;
    for (int i = 0; i < code.size(); )
      if (code[i] == '<') {
        int next_pos = -1;
        if (code.substr(i, 9) == "<![CDATA[") {
          if (tags.empty()) return false;
          next_pos = get_matched_pos("<![CDATA[", i+9, code);
          if (next_pos == -1) {
            return false;
          }
          i = next_pos + 3;
        } else if (code.substr(i, 2) == "</") {
          next_pos = get_matched_pos("</", i+2, code);
          if (next_pos == -1) {
            return false;
          }
          string tag_name = code.substr(i+2, next_pos-(i+2));
          if (tags.empty() || tag_name != tags.top()) {
            return false;
          }
          tags.pop();
          i = next_pos + 1;
          if (tags.empty() && i < code.size()) return false;
        } else {
          next_pos = get_matched_pos("<", i+1, code);
          if (next_pos == -1) {
            return false;
          }
          string tag_name = code.substr(i+1, next_pos-(i+1));
          if (!isTagNameValid(tag_name)) {
            return false;
          }
          tags.push(tag_name);
          i = next_pos + 1;
        }
    } else {
      if (tags.empty()) return false;
      ++i;
    }
    return tags.empty();
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>") << endl;
  cout << s.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>") << endl;
  cout << s.isValid("<A>  <B> </A>   </B>") << endl;
  cout << s.isValid("<DIV>  div tag is not closed  <DIV>") << endl;
  cout << s.isValid("<DIV>  unmatched <  </DIV>") << endl;
  cout << s.isValid("<DIV> closed tags with invalid tag name  <b>123</b> </DIV>") << endl;
  cout << s.isValid("<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>") << endl;
  cout << s.isValid("<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>") << endl;

  return 0;
}
