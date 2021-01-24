/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int main(){
    vector<string> p;
    int n;
    p.push_back("Washington");
    p.push_back("Adams");
    p.push_back("Jefferson");
    p.push_back("Madison");
    p.push_back("Monroe");
    p.push_back("Adams");
    p.push_back("Jackson");
    p.push_back("Van Buren");
    p.push_back("Harrison");
    p.push_back("Tyler");
    p.push_back("Polk");
    p.push_back("Taylor");
    p.push_back("Fillmore");
    p.push_back("Pierce");
    p.push_back("Buchanan");
    p.push_back("Lincoln");
    p.push_back("Johnson");
    p.push_back("Grant");
    p.push_back("Hayes");
    p.push_back("Garfield");
    p.push_back("Arthur");
    p.push_back("Cleveland");
    p.push_back("Harrison");
    p.push_back("Cleveland");
    p.push_back("McKinley");
    p.push_back("Roosevelt");
    p.push_back("Taft");
    p.push_back("Wilson");
    p.push_back("Harding");
    p.push_back("Coolidge");
    p.push_back("Hoover");
    p.push_back("Roosevelt");
    p.push_back("Truman");
    p.push_back("Eisenhower");
    p.push_back("Kennedy");
    p.push_back("Johnson");
    p.push_back("Nixon");
    p.push_back("Ford");
    p.push_back("Carter");
    p.push_back("Reagan");
    p.push_back("Bush");
    p.push_back("Clinton");
    p.push_back("Bush");
    p.push_back("Obama");
    cin>>n;
    cout<<p[n-1]<<endl;
    return 0;
}
