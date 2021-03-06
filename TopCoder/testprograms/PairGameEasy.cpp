/*
ID: ck89119
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
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;

int vis[1005][1005];
class PairGameEasy {
public:
  int inside(int x, int y, int c, int d) {
    if (x >= 1 && x <= c && y >= 1 && y <= d) return 1;
    else return 0;
  }

  int dfs(int a, int b, int c, int d) {
    if (a == c && b == d) return 1;
    if (a > c || b > d) return 0;

    int x, y;
    int ans = 0;
    x = a + b; y = b;
    if (inside(x, y, c, d) && !vis[x][y]) {
      vis[x][y] = 1;
      ans = dfs(x, y,c, d);
      vis[x][y] = 0;
    }

    if (ans) return 1;

    x = a; y = a + b;
    if (inside(x, y, c, d) && !vis[x][y]) {
      vis[x][y] = 1;
      ans = dfs(x, y,c, d);
      vis[x][y] = 0;
    }
    if (ans) return 1;

    return 0;
  }


	string able(int a, int b, int c, int d) {
    CLR(vis, 0);
    vis[a][b] = 1;
    if (dfs(a, b, c, d)) return "Able to generate";
    else return "Not able to generate";
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	PairGameEasy *obj;
	string answer;
	obj = new PairGameEasy();
	clock_t startTime = clock();
	answer = obj->able(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;
	int p3;
	string p4;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 2;
	p2 = 3;
	p3 = 5;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 2;
	p2 = 2;
	p3 = 1;
	p4 = "Not able to generate";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 2;
	p2 = 2;
	p3 = 999;
	p4 = "Not able to generate";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 2;
	p2 = 2;
	p3 = 1000;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 47;
	p1 = 58;
	p2 = 384;
	p3 = 221;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 1000;
	p1 = 1000;
	p2 = 1000;
	p3 = 1000;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING












//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
