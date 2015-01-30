#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;
typedef complex<ll> cll;
typedef complex<ld> cld;
#define Size(x) (int(x.size()))
#define LET(k,val) typeof(val) k = (val)
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))
#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (&#8211;&#8211;k)
#define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k < (b); ++k) if(cond) break, k)
#define LAST(k,a,b,con) CLC(LET(k, b); while((a) <= (&#8211;&#8211;k)) if(con) break, k)
#define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) < (b))
#define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k < (b); ++k) {act;}, R##k)
#define SUMTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k += (x))
#define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
#define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
#define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
#define MAXTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &#8212;= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k < (b); ++k) act, R##k)
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
#define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
#define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make pair(x,k)).second)
#define INF 1000000000
int tcize(int n) {return n<INF ? n : -1;}
vi parsevi(string s) {
s = s + " ";
int q = 0;
vi res;
FOR(l,0, Size(s)) {
if(s[l] == ' ') { res.push_back(q); q = 0;}
else { q = q * 10 + s[l] - '0'; }
}
return res;
}
vs parsevs(string s) {
s = s + " ";
string q = "";
vs res;
FOR(l,0, Size(s)) {
if(s[l] == ' ') { res.push_back(q); q = "";}
else { q += s[l]; }
}
return res;
}
#define MKey(x) 
typedef typeof(memo) tmemo; tmemo::key type key = (x); 
if(memo.find(key) != memo.end()) return memo[key]
#define MRet(y) return (memo[key] = y)
template <class T> T operator | (complex<T> x, complex<T> y) {
return (x*conj(y)).real();
}
template <class T> T operator ^ (complex<T> x, complex<T> y) {
return (x*conj(y)).imag();
}
int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}
/*template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
template<class T> T operator >? (T x, T y) {return x>y?x:y;}
template<class T> T operator <? (T x, T y) {return x<y?x:y;}*/
#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)
string cts(char c) {string s=""; s+=c; return s;}
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
os << "{";
for(LET(k,v.begin()); k != v.end(); ++k) {os << (*k); os << ",";}
os << "}";
return os;
}
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p) {
return os << "(" << p.first << "," << p.second << "";
}
template<class T> ostream& operator<<(ostream& os, const set<T>& v) {
os << "{";
for(LET(k,v.begin()); k != v.end(); ++k) {os << (*k); os << ",";}
os << "}";
return os;
}
#ifdef floyd
FOR(k,0,100) FOR(i,0,100) FOR(j,0,100) w0[i][j] <?= w0[i][k] + w0[k][j];
#endif
#define BINFIRST(k,a,b,cond) CLC( LET(k##mIn, a); LET(k##mAx, b); while(k##mIn != k##mAx) { LET(k, (k##mIn+k##mAx)>>1); if(cond) k##mAx = k; else k##mIn = k+1; }, k##mIn )
#define like
#define aint !=
#define gotta
#define man
#define please
#define two 2
#define three 3
#define four 4
#define five 5
#define six 6
#define seven 7
#define eight 8
#define nine 9
#define ten 10
#define eleven 11
#define dozen 12
#define dozens *12
#define enough 999
#define plus +
