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

typedef pair<string, int> Pair;
map<string, int> s;
vector<Pair> res;

int cmp(const Pair &a, const Pair &b){
    return a.second<b.second;
}

int input(){
    char str[100];
    string tmp;
    int i=1;
    while (1){
        scanf("%s",str);
        tmp=str;
        if (tmp!="#") s.insert(MP(tmp,i++));
        else break;
    }
    return 0;
}

int output(){
    int i;
    sort(res.begin(),res.end(),cmp);
    for (i=0;i<res.size();i++){
        if (i&&res[i].first==res[i-1].first) continue;
        cout<<" "<<res[i].first;
    }

    cout<<endl;
    return 0;
}

int solve(){
    char str[100];
    string tmp;
    int i;
    while (1){
        scanf("%s",str);
        tmp=str;
        if (tmp=="#") break;
        if (s[tmp]){
            cout<<tmp<<" is correct\n";
        }
        else{
            string tmp1;
            res.clear();
            for (i=0;i<tmp.size();i++){
                tmp1=tmp;
                tmp1.erase(tmp1.begin()+i);
                //dump(tmp1);
                if (s[tmp1]) res.push_back(MP(tmp1,s[tmp1]));
            }
            for (i=0;i<tmp.size();i++){
                char j;
                tmp1=tmp;
                for (j='a';j<='z';j++){
                    tmp1[i]=j;
                    if (s[tmp1]) res.push_back(MP(tmp1,s[tmp1]));
                }
            }
            for (i=0;i<=tmp.size();i++){
                char j;
                for (j='a';j<='z';j++){
                    tmp1=tmp;
                    tmp1.insert(tmp1.begin()+i,j);
                    if (s[tmp1]) res.push_back(MP(tmp1,s[tmp1]));
                }
            }
            cout<<tmp<<":";
            output();
        }
    }
    return 0;
}



int main(){
//freopen("a.in","r",stdin);
//freopen("a.out","w",stdout);
    input();
    solve();
    return 0;
}
