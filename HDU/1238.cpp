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
#include <cstring>
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

int t,n;
vector<string> v;

int cmp(const string &a,const string &b){
    if (a.size()!=b.size()) return a.size()<b.size();
    else return a<b;
}

int find(string a,string b){
    string tmp=b;
    reverse(tmp.begin(),tmp.end());
    if (b.find(a)!=b.npos||tmp.find(a)!=tmp.npos) return 1;
    else return 0;
}

int main(){
    scanf("%d",&t);
    while (t--){
        string s;
        int res,k;
        scanf("%d",&n);
        v.clear();
        FR(i,0,n){
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),cmp);
        res=0;
        FR(i,0,v[0].size())
            FR(j,i+1,v[0].size()+1){
                //dump("##########")
                string ssub=v[0].substr(i,j-i);
                //dump(ssub)
                for (k=1;k<v.size();k++)
                    if (!find(ssub,v[k])) break;
                if (k>=v.size()) res=max(res,j-i);
            }

        cout<<res<<endl;
    }
    return 0;
}
