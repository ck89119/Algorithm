/*
ID: ck89119
PROG: prime3
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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int digit[5][5];
int isPrime[100000];
int k;
int sum, d;
string res[1000];

int init() {
    int i;
    for (i = 0; i < 100000; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (i = 2; i < 50000; i++)
        if (isPrime[i]) {
            int j = i + i;
            while (j < 100000) {isPrime[j] = 0; j+=i;}
        }
    for (i = 0; i < 10000; i++) isPrime[i] = 0;
    //dump("init over")
    return 0;
}

int solve() {
    int i, j;
    k = 0;
    digit[0][0] = d;
    for (digit[1][1] = 0; digit[1][1] <= 9; digit[1][1]++)
      for (digit[2][2] = 0; digit[2][2] <= 9; digit[2][2]++)
        for (digit[3][3] = 0; digit[3][3] <= 9; digit[3][3]++) {
          digit[4][4] = sum-digit[1][1]-digit[2][2]-digit[3][3]-digit[0][0];
          if (digit[4][4]<0||digit[4][4]>9) continue;
          int t1=digit[0][0]*10000+digit[1][1]*1000+digit[2][2]*100+digit[3][3]*10+digit[4][4]*1;
          if (!isPrime[t1]) continue;
          for (digit[4][0] = 1; digit[4][0] <= 9; digit[4][0] += 2)
            for (digit[3][1] = 0; digit[3][1] <= 9; digit[3][1]++)
              for (digit[1][3] = 0; digit[1][3] <= 9; digit[1][3]++) {
                digit[0][4] = sum - digit[4][0] - digit[3][1] - digit[2][2] - digit[1][3];
                if (digit[0][4]<0||digit[0][4]>9) continue;
                int t2=digit[4][0]*10000+digit[3][1]*1000+digit[2][2]*100+digit[1][3]*10+digit[0][4]*1;
                if (!isPrime[t2]) continue;
                for (digit[4][1] = 1; digit[4][1] <= 9; digit[4][1] += 2)
                  for (digit[0][1] = 1; digit[0][1] <= 9; digit[0][1]++) {
                    digit[2][1] = sum - digit[0][1] - digit[1][1] - digit[3][1] - digit[4][1];
                    if (digit[2][1]<0||digit[2][1]>9) continue;
                    int t3=digit[0][1]*10000+digit[1][1]*1000+digit[2][1]*100+digit[3][1]*10+digit[4][1]*1;
                    if (!isPrime[t3]) continue;
                    for (digit[4][3] = 1; digit[4][3] <= 9; digit[4][3] += 2) {
                        digit[4][2] = sum - digit[4][0] - digit[4][1] - digit[4][3] - digit[4][4];
                        if (digit[4][2]<0||digit[4][2]>9) continue;
                        int t4=digit[4][0]*10000+digit[4][1]*1000+digit[4][2]*100+digit[4][3]*10+digit[4][4]*1;
                        if (!isPrime[t4]) continue;
                        for (digit[0][3] = 1; digit[0][3] <= 9; digit[0][3]++) {
                            digit[2][3] = sum - digit[0][3] - digit[1][3]- digit[3][3]- digit[4][3];
                            if (digit[2][3]<0||digit[2][3]>9) continue;
                            int t5=digit[0][3]*10000+digit[1][3]*1000+digit[2][3]*100+digit[3][3]*10+digit[4][3]*1;
                            if (!isPrime[t5]) continue;
                            digit[0][2] = sum - digit[0][0] - digit[0][1]- digit[0][3]- digit[0][4];
                            if (digit[0][2]<0||digit[0][2]>9) continue;
                            t5=digit[0][0]*10000+digit[0][1]*1000+digit[0][2]*100+digit[0][3]*10+digit[0][4]*1;
                            if (!isPrime[t5]) continue;
                            for (digit[2][4] = 1; digit[2][4] <= 9; digit[2][4] += 2) {
                              digit[2][0] = sum - digit[2][1]- digit[2][2]- digit[2][3]- digit[2][4];
                              if (digit[2][0]<0||digit[2][0]>9) continue;
                              int t6=digit[2][0]*10000+digit[2][1]*1000+digit[2][2]*100+digit[2][3]*10+digit[2][4]*1;
                              if (!isPrime[t6]) continue;
                              for (digit[1][4] = 1; digit[1][4] <= 9; digit[1][4] += 2) {
                                digit[3][4] = sum - digit[0][4] - digit[1][4] - digit[2][4] - digit[4][4];
                                if (digit[3][4]<0||digit[3][4]>9) continue;
                                int t7=digit[0][4]*10000+digit[1][4]*1000+digit[2][4]*100+digit[3][4]*10+digit[4][4]*1;
                                if (!isPrime[t7]) continue;
                                for (digit[1][0] = 1; digit[1][0] <= 9; digit[1][0]++) {
                                  digit[3][0] = sum - digit[0][0] - digit[1][0] - digit[2][0] - digit[4][0];
                                  if (digit[3][0]<0||digit[3][0]>9) continue;
                                  int t8=digit[0][0]*10000+digit[1][0]*1000+digit[2][0]*100+digit[3][0]*10+digit[4][0]*1;
                                  if (!isPrime[t8]) continue;
                                  digit[1][2] = sum - digit[1][0] - digit[1][1] - digit[1][3] - digit[1][4];
                                  if (digit[1][2]<0||digit[1][2]>9) continue;
                                  t8=digit[1][0]*10000+digit[1][1]*1000+digit[1][2]*100+digit[1][3]*10+digit[1][4]*1;
                                  if (!isPrime[t8]) continue;
                                  digit[3][2] = sum - digit[3][0] - digit[3][1] - digit[3][3] - digit[3][4];
                                  if (digit[3][2]<0||digit[3][2]>9) continue;
                                  t8=digit[3][0]*10000+digit[3][1]*1000+digit[3][2]*100+digit[3][3]*10+digit[3][4]*1;
                                  if (!isPrime[t8]) continue;
                                  t8=digit[0][2]*10000+digit[1][2]*1000+digit[2][2]*100+digit[3][2]*10+digit[4][2]*1;
                                  if (!isPrime[t8]) continue;

                                  res[k] = "";
                                  for (i = 0; i < 5; i++)
                                    for (j = 0; j < 5; j++) res[k] += (digit[i][j] + '0');
                                  k++;
                                }
                              }
                            }
                        }
                    }
                  }
              }
        }

    sort(res, res+k);
    return 0;
}

int output() {
    int i, j, kk;
    //dump("output")
    if (kk = 0) {cout << "NONE" << endl; return 0;}
    for (kk = 0; kk < k; kk++) {
        if (kk) cout << endl;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++)
                cout << res[kk][i*5+j];
            cout << endl;
        }
    }
    return 0;
}

int main() {
    freopen("prime3.in", "r", stdin);
    freopen("prime3.out", "w", stdout);
    scanf("%d%d", &sum, &d);
    init();solve();output();
    return 0;
}
