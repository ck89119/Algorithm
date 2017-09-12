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
  string convert(int num) {
    if (num == 0) return "";

    string s1[20] = {
      "Zero",
      "One",
      "Two",
      "Three",
      "Four",
      "Five",
      "Six",
      "Seven",
      "Eight",
      "Nine",
      "Ten",
      "Eleven",
      "Twelve",
      "Thirteen",
      "Fourteen",
      "Fifteen",
      "Sixteen",
      "Seventeen",
      "Eighteen",
      "Nineteen"
    };
    string s2[10] = {
      "Zero",
      "Ten",
      "Twenty",
      "Thirty",
      "Forty",
      "Fifty",
      "Sixty",
      "Seventy",
      "Eighty",
      "Ninety"
    };

    string ans;
    if (num >= 100) {
      ans += s1[num/100] + " Hundred ";
      num %= 100;
    }
    if (num >= 20) {
      ans += s2[num/10] + " ";
      num %= 10;
    }
    if (num > 0) ans += s1[num] + " ";
    return ans;
  }

  string numberToWords(int num) {
    if (num == 0) return "Zero";

    string s4[4] = {
      "Zero",
      "Thousand",
      "Million",
      "Billion"
    };
    
    ll n = 1;
    int level = 0;
    while (n <= num) n *= 1000, ++level;
    n /= 1000, --level;

    string ans;
    while (num) {
      // dump(n), dump(level);
      int d = num / n;
      if (d > 0) {
        ans += convert(d); 
        if (level > 0) ans += s4[level] + " ";
      }
      num %= n; n /= 1000; --level;
    } 
    return ans.substr(0, ans.size() - 1);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.numberToWords(1000010) << endl;
  // cout << s.numberToWords(12345) << endl;
  // cout << s.numberToWords(1234567) << endl;
  // cout << s.numberToWords(1234567890) << endl;
  return 0;
}
