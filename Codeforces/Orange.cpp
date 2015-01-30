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


char toUp(char ch){
    if (ch>='a'&&ch<='z') ch=ch-'a'+'A';
    return ch;
}
char toLow(char ch){
    if (ch>='A'&&ch<='Z') ch=ch-'A'+'a';
    return ch;
}

int main(){
    string s;
    int a;
    int i;
    cin>>s>>a;
    for (i=0;i<s.size();i++){
        s[i]=toLow(s[i]);
        if (s[i]-'a'<a) s[i]=toUp(s[i]);
        else s[i]=toLow(s[i]);
    }

    cout<<s<<endl;
    return 0;
}
