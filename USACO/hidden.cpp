/*
ID: ck89119
PROG: hidden
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
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("hidden.in","r",stdin);
#define fout freopen("hidden.out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

int l;
char str[200005], ans_str[100005], min_char;
int pos[100005], pos_size, pre;
int ans;

int cmp(char* s1, char* s2) {
    int i;
    for (i = 0; i < l; ++i) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
    return 0;
}

int input() {
    string s, tmp;
    int i;
    cin >> l;
    s = "";
    while (cin >> tmp) s += tmp;
    min_char = 'z' + 1;
    for (i = 0; i < l; ++i) {
        str[i] = s[i];
        str[i+l] = s[i];
        if (str[i] < min_char) {
            min_char = str[i];
            pos_size = 0;
            pos[pos_size++] = i;
            pre = i;
        }
        else if (str[i] == min_char) {
            if (i != pre + 1) pos[pos_size++] = i;
            pre = i;
        }
    }
    return 0;
}

int solve() {
    int i;
    ans = 0;
    strncpy(ans_str, str, l);
    ans_str[l] = '\0';
    for (i = 0; i < pos_size; ++i) {
        int t = pos[i];
        if (cmp(str+t, ans_str) == -1) {
            ans = t;
            strncpy(ans_str, str+t, l);
            ans_str[l] = '\0';
        }
    }

    return 0;
}

int output() {
    cout << ans << endl;
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    output();
    return 0;
}
