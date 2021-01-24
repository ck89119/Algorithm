/*
ID: ck891191
PROG: cryptcow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
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
#define lowbit(x) ((x)&(-(x)))
#define MAXB 80
#define MAXH 3214567
#define DES 1670966 //destination Hash value

//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
typedef char STR[MAXB];

int elfhash(char * str) {
	unsigned int res = 0,g;
	while (*str)
	{
		res = (res << 4) + (*str++);
	    g = res & 0xF0000000;
		if (g) res ^= g >> 24;
		res &= ~g;
	}
	return res % MAXH;
}

inline void swap(int pos1,int pos2,int pos3,char *str,char *tmp) {
	//make sure that
	//str[pos1] == 'C ' str[pos2] == 'O' str[pos3] == 'W'
	char *ptr = tmp,len = strlen(str);
	memmove(ptr,str,pos1);
	ptr += pos1;
	memmove(ptr,str + pos2 + 1,pos3 - pos2 - 1);
	ptr += pos3 - pos2 - 1;
	memmove(ptr,str + pos1 + 1,pos2 - pos1 - 1);
	atr += pos2 - pos1 - 1;
	memmove(ptr,str + pos3 + 1,len - pos3 - 1);
	tmp[len - 3] = 0;
}


bool hash[MAXH],exist[MAXH];
int Ccnt = 0,Ocnt = 0,Wcnt = 0,maxstep;
int prefix[MAXB],suffix[MAXB];

bool search(int step,char *str) {

	int len = strlen(str),hv = elfhash(str);
	int Cpos[10],Opos[10],Wpos[10];
	int Ccnt,Ocnt,Wcnt,prev = 0,lC,lO,lW,fpos = -1;
	STR tmp;

	Ccnt = Ocnt = Wcnt = 0;

	if (hv == DES) return 1; //Success
	for (int i = 0; i < len; i++)
		if (str[i] == 'C' || str[i] == 'O' || str[i] == 'W')
		{
			if (fpos < 0) fpos = i;
			if (i - prev > 1)
			{
				memmove(tmp,str + prev,i - prev);
				tmp[i - prev] = 0;
				if (!exist[elfhash(tmp)]) return 0;
			}
			prev = i + 1;

			if (str[i] == 'C') {Cpos[++Ccnt] = i; lC = i; if (Ccnt == 1 && (Ocnt || Wcnt)) return 0;}
				else if (str[i] == 'O') {Opos[++Ocnt] = i; lO = i;}
				else if (str[i] == 'W') {Wpos[++Wcnt] = i; lW = i;}

		}//scan

	if (hash[hv] || step > maxstep) return 0;
	if (lW < lO || lW < lC) return 0;

	memmove(tmp,str,fpos);
	tmp[fpos] = 0;
	if (elfhash(tmp) != prefix[fpos - 1]) return 0;

	memmove(tmp,str + lW + 1,len - lW - 1);
	tmp[len - lW - 1] = 0;
	if (elfhash(tmp) != suffix[len - lW - 2]) return 0;

	hash[hv] = 1;
		for (int j = 1; j <= Ocnt; j++)
			for (int i = 1; i <= Ccnt; i++)
				if (Opos[j] > Cpos[i])
					for (int k = Wcnt; k >= 1; k--)
						if (Wpos[k] > Opos[j])
						{
							swap(Cpos[i],Opos[j],Wpos[k],str,tmp);
							if (search(step + 1,tmp)) return 1;
						}
	return 0;
}

int main() {

	STR str,tmp,dstr = "Begin the Escape execution at the Break of Dawn";
    int len;

	freopen("cryptcow.in","r",stdin);
	freopen("cryptcow.out","w",stdout);
	memset(hash,0,sizeof(hash));

	for (int i = 0; i < 47; i++)
		for (int j = i; j < 47; j++)
		{
			memmove(tmp,dstr + i, j - i + 1);
			tmp[j - i + 1] = 0;
			if (i == 0) prefix[j] = elfhash(tmp);
			exist[elfhash(tmp)] = 1;
		}
	for (int i = 0; i < 47; i++)
	{
		memmove(tmp,dstr + 46 - i,i + 1);
		tmp[i + 1] = 0;
		suffix[i] = elfhash(tmp);
	}
	//pre calc

	fgets(str,MAXB,stdin);
	str[len = (strlen(str) - 1)] = 0;

	for (int i = 0; i < len; i++)
		if (str[i] == 'C') ++Ccnt;
			else if (str[i] == 'O') ++Ocnt;
				else if (str[i] == 'W') ++Wcnt;

	if  (elfhash(str) == DES) printf("%d %d\n",1,0);
		else if (Ccnt != Ocnt || Ocnt != Wcnt || ((len - 47) % 3)) printf("%d %d\n",0,0);
			else
			{
				maxstep = (len - 47) / 3;
				if (search(1,str)) printf("%d %d\n",1,Ccnt);
					else printf("%d %d\n",0,0);
			}

	return 0;
}
