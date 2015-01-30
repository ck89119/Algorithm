/*
ID: ck89119
PROG: vans
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("vans.in","r",stdin);
#define fout freopen("vans.out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long
const int maxlen = 1000;

class HP {
public:
    int len, s[maxlen];
    HP() {(*this)=0;}
    HP(int inte) {(*this)=inte;}
    HP(const char* str)	{(*this)=str;}
    friend ostream& operator<<(ostream &cout, const HP&x);
    HP operator=(int inte);
    HP operator=(const char* str);
    HP operator-(const HP &b);
    HP operator+(const HP &b);
	HP operator*(const HP &b);
    //HP operator/(const HP &b);
	//HP operator%(const HP &b);
    int Compare(const HP &b);
};

ostream& operator<<(ostream &cout, const HP &x) {
    for (int i = x.len; i >= 1; --i) cout << x.s[i];
    return cout;
}

HP HP::operator=(const char* str) {
    len = strlen(str);
    for (int i = 1; i <= len; ++i) s[i] = str[len-i] - '0';
    return (*this);
}

HP HP::operator=(int inte) {
    if (inte == 0) {
        len = 1; s[1] = 0;
        return (*this);
    }
    for (len = 0; inte > 0;) {
        s[++len] = inte % 10;
        inte /= 10;
    }
    return (*this);
}

HP HP::operator*(const HP &b) {
    int i, j;
    HP c;
    c.len = len + b.len;
    for (i = 1; i <= c.len; ++i) c.s[i] = 0;
    for (i = 1; i <= len; ++i)
        for (j = 1; j <= b.len; ++j)
            c.s[i+j-1] += s[i]*b.s[j];
    for (i = 1; i < c.len; ++i) {
        c.s[i+1] += c.s[i]/10;
        c.s[i] %= 10;
    }
    while (c.s[i]) {
        c.s[i+1] = c.s[i]/10;
        c.s[i]%=10;
        i++;
    }
    while (i > 1 && !c.s[i]) i--;
    c.len=i;
    return c;
}

HP HP::operator+(const HP &b) {
    int  i;
    HP c;
    c.s[1] = 0;
    for (i = 1; i <= len || i <= b.len || c.s[i]; i++) {
        if(i <= len) c.s[i] += s[i];
        if(i <= b.len) c.s[i] += b.s[i];
        c.s[i+1] = c.s[i] / 10;
        c.s[i] %= 10;
    }
    c.len = i - 1;
    if (c.len == 0) c.len = 1;
    return c;
}

HP HP::operator-(const HP &b) {
    int i ,j;
    HP c;
    for (i = 1, j = 0; i <= len; ++i) {
        c.s[i] = s[i] - j;
        if (i <= b.len) c.s[i] -= b.s[i];
        if (c.s[i] < 0) {
            j = 1;
            c.s[i] += 10;
        }
        else j = 0;
    }
    c.len = len;
    while (c.len > 1 && !c.s[c.len]) c.len--;
    return c;
}

int HP::Compare(const HP &y) {
    if (len > y.len) return 1;
    if (len < y.len) return -1;
    int i = len;
    while ((i > 1) && (s[i] == y.s[i])) i--;
    return s[i] - y.s[i];
}

int n;
HP f[1005];

int input() {
	cin >> n;
    return 0;
}

int solve() {
    int i;
    f[1] = 0;
    f[2] = 2;
    f[3] = 4;
    f[4] = 12;
    for (i = 5; i <= n; ++i)
        f[i] = f[i-1] + f[i-1] + f[i-2] + f[i-2] - f[i-3] - f[i-3] + f[i-4];
    return 0;
}

int output() {
	cout << f[n] << endl;
    return 0;
}

int main() {
    fin fout
    ios::sync_with_stdio(false);
    input();
    solve();
    output();
    return 0;
}
