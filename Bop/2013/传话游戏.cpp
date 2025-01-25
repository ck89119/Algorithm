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
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

map<string ,string> trans;
int t,n,m;
string alice_s;

int input(){
    string a,b;
    int i,j;
    scanf("%d%d",&n,&m);
    trans.clear();
    for (i=0;i<m;i++){
        cin>>a>>b;//dump(a)dump(b)
        trans.insert(MP(a,b));
    }
    getline(cin,a);getline(cin,a);
    alice_s=a;
//    i=0;j=0;alice.clear();
//    while (j<a.size()){
//        while (a[j]!=' '&&j<a.size()) j++;
//        alice.push_back(a.substr(i,j-i));
//        j++;i=j;
//    }
    //dump(alice);
    return 0;
}

int solve(){
    int i,j,k;
    for (k=0;k<n-1;k++){
        int ii,jj;
        ii=0;
        while(alice_s[ii]==' '&&ii<alice_s.size()) ii++;
        jj=ii;
        while (jj<alice_s.size()){
            string tmp;
            while (alice_s[jj]!=' '&&jj<alice_s.size()) jj++;
            tmp=alice_s.substr(ii,jj-ii);
            if (trans.count(tmp)){
                alice_s.replace(ii,jj-ii,trans[tmp]);
                jj+=trans[tmp].size()-jj+ii;
            }
            ii=jj;
            while(alice_s[ii]==' '&&ii<alice_s.size()) ii++;
            jj=ii;
        }
    }
    cout<<alice_s<<endl;
//    for (i=0;i<alice.size()-1;i++)
//        cout<<alice[i]<<' ';
//    cout<<alice[i]<<endl;
    return 0;
}

int main(){
    int i;
    scanf("%d",&t);
    for (i=1;i<=t;i++){
        input();
        cout<<"Case #"<<i<<": ";
        solve();
    }


    return 0;
}
