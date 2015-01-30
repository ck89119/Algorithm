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

int n, m, atk[105], def[105], c[105];
int size_atk, size_def;

int input() {
    int i;
    string s;
    cin>>n>>m;
    size_atk = size_def = 0;
    for (i = 0; i < n; i++) {
        cin>>s;
        if (s == "ATK") cin>>atk[size_atk++];
        else cin>>def[size_def++];
    }
    for (i = 0; i < m; i++) cin>>c[i];
    sort(atk, atk+size_atk);
    sort(def, def+size_def);
    sort(c, c+m);
    return 0;
}

int lager(int arr[], int size_arr, int x) {
    int i;
    for (i = 0; i < size_arr; i++)
        if (arr[i] > x) return i;
    return -1;
}

int lagerOrEqual(int arr[], int size_arr, int x) {
    int i;
    for (i = 0; i < size_arr; i++)
        if (arr[i] >= x) return i;
    return -1;
}

int killAll() {
    int i;
    int sum = 0;
    for (i = 0; i < size_def; i++) {
        int p = lager(c, m, def[i]);
        if (p == -1) return 0;
        c[p] = -1;
    }

    for (i = 0; i < size_atk; i++) {
        int p = lagerOrEqual(c, m, atk[i]);
        if (p == -1) return 0;
        sum += (c[p] - atk[i]);
        c[p] = -1;
    }

    for (i = 0; i < m; i++)
        if (c[i] != -1) sum += c[i];

    return sum;
}

int process() {
    int i, k;
    int res;

    res = 0;
    for (k = 1; k <= min(m, size_atk); k++) {
        int sum = 0;
        for (i = 0; i < k; i++)
            sum += max(0, c[m-k+i]-atk[i]);
        res = max(res, sum);
    }
    res = max(res, killAll());
    cout<<res<<endl;
    return 0;
}

int main() {
    input();
    process();
    return 0;
}




















//int m, n;
//int c[105], d_a[105], d_d[105];
//int size_a, size_d;
//int tmp_c[105];
//
//int main(){
//    int i, j, k;
//    int res;
//    int flag;
//    //freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//
//    scanf("%d%d", &n, &m);
//    size_a = size_d = 0;
//    for (i = 0; i < n; i++) {
//        string s;
//        cin>>s;
//        if (s == "ATK") cin>>d_a[size_a++];
//        else cin>>d_d[size_d++];
//    }
//    for (i = 0; i < m; i++) cin>>c[i];
//    sort(d_a, d_a+size_a);
//    sort(d_d, d_d+size_d);
//    res = 0;
//
//    for (i = 0; i < m; i++) tmp_c[i] = c[i];
//    sort(tmp_c, tmp_c+m);
//    for (k = 1; k <= min(m, size_a); k++) {
//        int sum = 0;
//        for (i = 0; i < k; i++)
//            sum += max(0, tmp_c[m-k+i]-d_a[i]);
//        res = max(res, sum);
//    }
////    k = 0;
////    for (i = 0, j = m-1; i < size_a && j >= 0; i++, j--)
////        if (tmp_c[j] >= d_a[i]) k += (tmp_c[j]-d_a[i]);
////        else break;
////    res = max(k, res);
//
//    for (i = 0; i < size_d; i++) {
//        flag = 0;
//        for (j = 0; j < m; j++)
//            if (tmp_c[j] > d_d[i]) {
//                tmp_c[j] = -1;
//                flag = 1;
//                break;
//            }
//        if (!flag) break;
//    }
//    if (flag) {
//        int sum = 0;
//        for (i = 0; i < size_a; i++) {
//            flag = 0;
//            for (j = 0; j < m; j++)
//                if (tmp_c[j] >= d_a[i]) {
//                    sum += (tmp_c[j]-d_a[i]);
//                    tmp_c[j] = -1;
//                    flag = 1;
//                    break;
//                }
//            if (!flag) break;
//        }
//        if (flag) {
//            for (i = 0; i < m; i++)
//                if (tmp_c[i] != -1) sum += tmp_c[i];
//            res = max(res, sum);
//        }
//    }
//
//    cout<<res<<endl;
//    return 0;
//}
