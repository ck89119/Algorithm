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
const int maxlen = 10000;
//int dir[3][2]={{1,0},{0,-1},{0,1}};
//int grid[105][210];
int n;
//long long res;
//
//int dfs(int k, int x, int y){
//    int i,d;
//    if (k==n){
//        res++;
//        return 0;
//    }
//    for (d=0;d<3;d++)
//        if (!grid[x+dir[d][0]][y+dir[d][1]]){
//            grid[x+dir[d][0]][y+dir[d][1]]=1;
//            dfs(k+1,x+dir[d][0],y+dir[d][1]);
//            grid[x+dir[d][0]][y+dir[d][1]]=0;
//        }
//    return 0;
//}
class HP {
public:
    int len,s[maxlen];
    HP()  {(*this)=0;}
    HP(int inte )  {(*this)=inte;}
    HP(const char* str)	{(*this)=str;}
    friend ostream& operator<<(ostream &cout,const HP&x);
    HP operator=(int inte);
    HP operator=(const char* str);
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

HP HP::operator*(const HP &b)
{
         int i,j ;
         HP c;
         c.len=len+b.len;
         for(i=1;i<=c.len;i++) c.s[i]=0;
         for(i=1;i<=len;i++)
            for(j=1;j<=b.len;j++)
                c.s[i+j-1]+=s[i]*b.s[j];
         for(i=1;i<c.len;i++) {c.s[i+1]+=c.s[i]/10;c.s[i]%=10;}
         while(c.s[i]) {c.s[i+1]=c.s[i]/10; c.s[i]%=10; i++;}
         while(i>1&&!c.s[i])  i--;
         c.len=i ;
         return  c ;
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

HP HP::operator-(const HP &b)
{
         int i ,j ; HP c;
         for(i=1,j=0; i<=len; i++) {
              c.s[i]=s[i]-j;
              if(i<=b.len) c.s[i]-=b.s[i];
              if(c.s[i]<0){j=1;c.s[i]+=10;}
              else  j=0;
         }
         c.len=len;
         while(c.len>1&&!c.s[c.len]) c.len--;
         return  c;
}

int HP::Compare(const HP&y)
{
         if(len>y.len) return 1;
         if(len<y.len) return -1;
         int  i=len;
         while ((i>1)&&(s[i]==y.s[i]))  i--;
         return  s[i]-y.s[i];
}

HP HP::operator/(const HP &b)
{
         int i,j;
         HP d(0),c;
         for(i=len;i>0;i--) {
            if (!(d.len==1&&d.s[1]==0)) {
                for(j=d.len;j>0;j--) d.s[j+1]=d.s[j];
                ++d.len;
            }
            d.s[1]=s[i];
            c.s[i]=0;
            while ((j=d.Compare(b))>=0){
                  d=d-b;
                  c.s[i]++;
                  if (j ==0) break ;
            }
         }
         c.len=len;
         while((c.len>1)&&(c.s[c.len]==0)) c.len--;
         return  c;
}

HP HP::operator%(const HP &b)
{
         int i,j;
         HP d(0);
         for(i=len;i>0;i--) {
             if (!(d.len==1&& d.s[1]==0)) {
                 for(j=d.len;j>0;j--) d.s[j+1]=d.s[j];
                 ++d.len;
             }
             d.s[1]=s[i];
             while((j=d.Compare(b))>=0){
                 d=d-b ;
                 if(j==0) break ;
             }
         }
         return  d ;
}

HP  f[105],g[105];

int main(){
    int i;
    scanf("%d",&n);
    f[1]=1;g[1]=2;
    for (i=2;i<=n;i++){
        f[i]=f[i-1]+g[i-1];
        g[i]=f[i-1]+f[i];
    }
    cout<<f[n]+g[n]<<endl;
//    CL(grid,0);grid[1][105]=1;
//    res=0;
//    dfs(0,1,105);
//    printf("%lld\n",res);
    return 0;
}
