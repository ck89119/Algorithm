#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

/*
const int INTEGER = 0;
const int PLUS = 1;
const int MINUS = 2;
const int MUL = 3;
const int DIV = 4;
const int LPAR = 5;
const int RPAR = 6;
const int NIL = 7;

class Token {
 public:
  string value;
  int type;
  Token() {}
  Token(string _value, int _type): value(_value), type(_type) {}

  int get_int_value() {
    int ans = 0;
    for (auto ch: value)
      ans = ans * 10 + ch - '0';
    return ans;
  }
};

class Lexer {
 public:
  string text;
  unsigned int cur;
  Lexer() {}
  Lexer(string _text): text(_text), cur(0) {}

  bool is_digit(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    return false;
  }

  Token get_int() {
    unsigned int i = cur;
    while (i < text.size() && is_digit(text[i])) ++i;
    Token ans(text.substr(cur, i-cur), INTEGER); 
    cur = i;
    return ans;
  }

  Token get_next_token() {
    while (cur < text.size()) {
      if (text[cur] == ' ') { ++cur; continue; }
      if (is_digit(text[cur])) return get_int();
      if (text[cur] == '+') { ++cur; return Token("+", PLUS); }
      if (text[cur] == '-') { ++cur; return Token("-", MINUS); }
      if (text[cur] == '*') { ++cur; return Token("*", MUL); }
      if (text[cur] == '/') { ++cur; return Token("/", DIV); }
      if (text[cur] == '(') { ++cur; return Token("(", LPAR); }
      if (text[cur] == ')') { ++cur; return Token(")", RPAR); }
    }
    return Token("", NIL);
  }
};

class Solution {
 public:
  Token cur_token;
  Lexer *lexer;
  
  int eat(int target_type) {
    if (cur_token.type == target_type) {
      cur_token = lexer->get_next_token();
      return 0;
    }
    return -1;
  }

  int factor() {
    Token token = cur_token;
    if (token.type == INTEGER) {
      eat(INTEGER);
      return token.get_int_value();
    } else if (token.type == LPAR) {
      eat(LPAR);
      int ans = expr();
      eat(RPAR);
      return ans;
    }
    return -1;
  }

  int term() {
    int ans = factor();
    while (cur_token.type == MUL || cur_token.type == DIV) {
      if (cur_token.type == MUL) {
        eat(MUL);
        ans = ans * factor();
      }
      else if (cur_token.type == DIV) {
        eat(DIV);
        ans = ans / factor();
      }
    }
    return ans;
  }

  int expr() {
    int ans = term();
    while (cur_token.type == PLUS || cur_token.type == MINUS) {
      if (cur_token.type == PLUS) {
        eat(PLUS);
        ans = ans + term();
      }
      else if (cur_token.type == MINUS) {
        eat(MINUS);
        ans = ans - term();
      }
    }
    return ans;
  }

  int calculate(string s) {
    lexer = new Lexer(s);
    cur_token = lexer->get_next_token();
    return expr();
  }
};
*/

class Solution {
 public:
  unsigned int cur;
  bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
  }
  
  int get_int(const string &s) {
    int ans = 0;
    while (cur < s.size() && !is_digit(s[cur])) ++cur;
    while (cur < s.size() && is_digit(s[cur])) {
      ans = ans * 10 + s[cur] - '0';
      ++cur;
    }
    return ans;
  }  

  int calculate(string s) {
    stack<char> op;
    stack<int> nums;
    for (cur = 0; cur < s.size(); ) {
      if (s[cur] == ' ') { ++cur; continue; }
      if (is_digit(s[cur])) {
        int n = get_int(s);
        nums.push(n);
      } else {
        char oper = s[cur];
        if (oper == '+' || oper == '-') {
          op.push(oper);
          ++cur;
        } else {
          int n1 = nums.top(); nums.pop();
          int n2 = get_int(s);
          nums.push(oper == '*' ? n1 * n2 : n1 / n2);
        }
      }
    }

    stack<char> tmp_op;
    stack<int> tmp_nums;
    while (!op.empty()) { tmp_op.push(op.top()); op.pop(); }
    while (!nums.empty()) { tmp_nums.push(nums.top()); nums.pop(); }
    op = tmp_op; nums = tmp_nums;

    while (!op.empty()) {
      int n1 = nums.top(); nums.pop();
      int n2 = nums.top(); nums.pop();
      char oper = op.top(); op.pop();
      nums.push(oper == '+' ? n1 + n2 : n1 - n2);
    }
    if (nums.empty()) return 0;
    else return nums.top();
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.calculate("1-1+2") << endl;
  return 0;
}
