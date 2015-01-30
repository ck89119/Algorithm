/*
ID: ck891191
PROG: buylow
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
const int maxlen = 100;

class HP {
public:
    int len,s[maxlen];
    HP()  {(*this)=0;}
    HP(int inte )  {(*this)=inte;}
    HP(const char* str)	{(*this)=str;}
    friend ostream& operator<<(ostream &cout,const HP&x);
    HP operator=(int inte);
    HP operator=(const char* str);
    HP operator=(const HP &a);
    HP operator-(const HP &b);
    HP operator+(const HP &b);
	HP operator*(const HP &b);
    HP operator/(const HP &b);
	HP operator%(const HP &b);
    int  Compare(const HP &b);
};

ostream& operator<<(ostream &cout,const HP &x)
{
         for(int  i=x.len;i>=1;i--) cout<<x.s[i];
         return cout;
}

HP HP::operator=(const char* str)
{
         len=strlen(str);
         for(int i=1;i<=len;i++) s[i]=str[len-i]-'0';
         return  (*this);
}
HP HP::operator=(int inte)
{
         if(inte==0) {len=1; s[1]=0; return	(*this);};
         for(len=0;inte>0;){s[++len]=inte%10;inte/=10;};
         return	(*this);
}
HP HP::operator=(const HP &a)
{
         len=a.len;
         for(int i=1;i<=len;i++) s[i]=a.s[i];
         return  (*this);
}
HP HP::operator+(const HP &b)
{
         int  i;
         HP c;
         c.s[1]=0;
         for(i=1; i<=len||i<=b.len||c.s[i];i++) {
             if(i<=len) c.s[i]+=s[i];
             if(i<=b.len) c.s[i]+=b.s[i];
             c.s[i+1]=c.s[i]/10;
             c.s[i]%=10;
         }
         c.len=i-1;
         if (c.len==0) c.len=1;
         return  c ;
}

struct node {
    int times;
    HP n;
    vector<int> pre;
};
int n;
int price[5000+5];
node l[5000+5];

int main(){
    int i, j;
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
        l[i].times = 1; l[i].n = 1;
    }
    price[n] = 0;
    l[n].times = 1; l[n].n = 1;
    for (i = 0; i <= n; i++)
        for (j = i-1; j >= 0; j--)
            if (price[i] < price[j]){
                if (l[i].times < l[j].times+1) {
                    //dump(price[i])dump(price[j])
                    l[i].times = l[j].times + 1;
                    l[i].n = l[j].n;
                    l[i].pre.clear();
                    l[i].pre.push_back(price[j]);
                }
                else if (l[i].times == l[j].times+1) {
                    int k;
                    for (k = 0; k < l[i].pre.size(); k++)
                        if (price[j] == l[i].pre[k]) break;
                    if (k >= l[i].pre.size()) {
                        l[i].pre.push_back(price[j]);
                        l[i].n = l[i].n + l[j].n;
                    }
                }
            }
    printf("%d ", l[n].times-1);
    cout<<l[n].n<<endl;
    return 0;
}
