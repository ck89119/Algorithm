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

int h[200005], m[200005], h_size, m_size;
string s;

int main(){
    int i, j;
    long long res;
    cin >> s;
    h_size = m_size = 0;
    for (i = 0; i < s.size(); ) {
        if (s.substr(i, 5) == "heavy") {
            h[h_size++] = i;
            i += 5;
        }
        else if (s.substr(i, 5) == "metal") {
            m[m_size++] = i;
            i +=5;
        }
        else i++;
    }
    res = 0; j = 0;
    for (i = 0; i < h_size; i++) {
        while (m[j] < h[i] && j < m_size) j++;
        res += (m_size - j);
    }
    cout << res << endl;
    return 0;
}
