/*
ID: ck89119
PROG: frameup
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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int h, w;
char pic[35][35];
int up[35][35], indeg[35];

struct Node {
    char ch;
    int l, r, u, d;
    int init() {
        l = u = INF;
        r = d = -INF;
        return 0;
    }
    int update(int i, int j) {
        l = min(l, j);
        r = max(r, j);
        u = min(u, i);
        d = max(d, i);
        return 0;
    }
}frame[905];
int frameSize;
vector<string> res;

int input() {
    int i, j, k;
    scanf("%d%d", &h, &w);getchar();
    for (i = 0; i < h; i++)
        scanf("%s", &pic[i]);
    CLR(up, 0); CLR(indeg, 0);
    frameSize = 0;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++) {
            char ch = pic[i][j];
            int flag = 0;
            if (ch == '.') continue;
            for (k = 0; k < frameSize; k++)
                if (ch == frame[k].ch) {flag = 1; break;}
            if (!flag) {
                frame[frameSize].init();
                frame[frameSize].update(i, j);
                frame[frameSize++].ch = ch;
            }
            else frame[k].update(i, j);
        }

    for (k = 0; k < frameSize; k++) {
        int kk;
        j = frame[k].l;
        for (i = frame[k].u; i <= frame[k].d; i++)
            if (pic[i][j] != '.' && pic[i][j] != frame[k].ch) {
                for (kk = 0; kk < frameSize; kk++)
                    if (frame[kk].ch == pic[i][j]) {up[k][kk] = 1; break;}
            }
        j = frame[k].r;
        for (i = frame[k].u; i <= frame[k].d; i++)
            if (pic[i][j] != '.' && pic[i][j] != frame[k].ch) {
                for (kk = 0; kk < frameSize; kk++)
                    if (frame[kk].ch == pic[i][j]) {up[k][kk] = 1; break;}
            }
        i = frame[k].u;
        for (j = frame[k].l+1; j < frame[k].r; j++)
            if (pic[i][j] != '.' && pic[i][j] != frame[k].ch) {
                for (kk = 0; kk < frameSize; kk++)
                    if (frame[kk].ch == pic[i][j]) {up[k][kk] = 1; break;}
            }
        i = frame[k].d;
        for (j = frame[k].l+1; j < frame[k].r; j++)
            if (pic[i][j] != '.' && pic[i][j] != frame[k].ch) {
                for (kk = 0; kk < frameSize; kk++)
                    if (frame[kk].ch == pic[i][j]) {up[k][kk] = 1; break;}
            }
    }
    for (i = 0; i < frameSize; i++)
        for (j = 0; j < frameSize; j++)
            if (up[i][j]) indeg[j]++;
//    dump(frameSize)
//    for (i = 0; i < frameSize; i++) cout << frame[i].ch; cout << endl;
//    out(indeg, frameSize);
//    for (i = 0; i < frameSize; i++){
//        for (j = 0; j < frameSize; j++)
//            cout << up[i][j];
//        cout << endl;}
    return 0;
}

int dfs(int k, string s) {
//    dump(k) dump(s)
//    out(indeg, frameSize);
    if (k == frameSize) {
        res.PB(s);
        return 0;
    }

    int i, j;
    for (i = 0; i < frameSize; i++)
        if (indeg[i] == 0) {
            indeg[i] = -1;
            for (j = 0; j < frameSize; j++)
                if (up[i][j]) indeg[j]--;
            dfs(k+1, s+frame[i].ch);
            for (j = 0; j < frameSize; j++)
                if (up[i][j]) indeg[j]++;
            indeg[i] = 0;
        }

    return 0;
}

int topsort() {
    string s = "";
    dfs(0, s);
    return 0;
}

int output() {
    int i;
    sort(res.begin(), res.end());
    for (i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}

int main() {
    freopen("frameup.in","r",stdin);
    freopen("frameup.out","w",stdout);
    input();
    topsort();
    output();
    return 0;
}
