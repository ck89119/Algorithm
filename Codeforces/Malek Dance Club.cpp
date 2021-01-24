/*
ID: ck891191
PROG:
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
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const long long MOD = 1000000007;

int n;
string s;

long long twoPower(int x) {
    long long t;
    if (x == 0) return 1;
    if (x == 1) return 2;
    t = twoPower(x/2);
    if (x%2 == 0) {
        return (t*t)%MOD;
    }
    else {
        return (t*t)%MOD*2%MOD;
    }
}

int input() {
    cin>>s;
    n = s.size();
    return 0;
}

long long rec(int i) {
    if (i == n-1) {
        return s[i]-'0';
    }

    if (s[i] == '0') return 2*rec(i+1)%MOD;
    else return (2*rec(i+1)+twoPower(2*(n-i-1)))%MOD;
}

int main(){
    input();
    cout << rec(0) << endl;
    return 0;
}
