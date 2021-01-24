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

struct node{
    string str;
    int p;
};
string a,b;
queue<node> q;
set<string> st;

int main(){
    node tmp;
    int i,n;
    cin>>a>>b;//dump(a)dump(b)
    while (!q.empty()) q.pop();
    for (i=0;i<a.size();i++)
        if (a[i]=='1') n++;
    tmp.str=a;tmp.p=n%2;
    q.push(tmp);
    st.insert(a);
    while (!q.empty()){
        node t;
        tmp=q.front();q.pop();
        if (tmp.str==b) {
            cout<<"YES\n";
            return 0;
        }
        if (tmp.str.size()){
            t.str=tmp.str.substr(1);
            if (tmp.str[0]=='0') t.p=tmp.p;
            else t.p=tmp.p^1;
            if (!st.count(t.str)){
                //dump(t.str)
                q.push(t);
                st.insert(t.str);
            }
        }
        if (tmp.str.size()<=b.size()){
            t=tmp;
            if (t.p) {t.str+='1';t.p=0;}
            else t.str+='0';
            if (!st.count(t.str)){
                //dump(t.str)
                q.push(t);
                st.insert(t.str);
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
