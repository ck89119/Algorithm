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
#include <ctime>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;


class EnclosingTriangleColorful {
public:
    int res;
    int valid[1200][1200];
    int nextSide[1200];
    int px[1200], py[1200];

    int cross(int x0, int y0, int x1, int y1, int x2, int y2) {
        return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
    }

    int isValid(int i, int j, vector<int> &x, vector<int> &y) {
        int k;
        for (k = 0; k < x.size(); k++)
            if (cross(x[k], y[k], px[i], py[i], px[j], py[j]) > 0) return 0;
        return 1;
    }

	int getNumber(int m, vector <int> x, vector <int> y) {
		int i, j, k, s;
		int t = 0;
		for (s = 0; s < 4; s++)
            for (i = 1; i < m; i++) {
                int tx[4] = {0, i, m, m-i};
                int ty[4] = {i, m, m-i, 0};
                px[t] = tx[s];
                py[t] = ty[s];
                nextSide[t++] = (s+1)*(m-1);
            }

        for (i = 0; i < t; i++)
            for (j = nextSide[i]; j < t; j++) {
                valid[i][j] = isValid(i, j, x, y);
                valid[j][i] = isValid(j, i, x, y);
            }

        res = 0;
        for (i = 0; i < t; i++)
            for (j = nextSide[i]; j < t; j++)
                for (k = nextSide[j]; k < t; k++)
                    if (valid[i][j] && valid[j][k] && valid[k][i]) res++;

        return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	EnclosingTriangleColorful *obj;
	int answer;
	obj = new EnclosingTriangleColorful();
	clock_t startTime = clock();
	answer = obj->getNumber(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <int> p1;
	vector <int> p2;
	int p3;

	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,3,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 8;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 7;
	int t1[] = {1,1,6,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,6,1,6};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 4;
	int t1[] = {2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 72;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 10;
	int t1[] = {2,6,7,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {7,7,9,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 52;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 15;
	int t1[] = {7,6,5,4,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,4,7,10,13};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 150;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 300;
	int t1[] = {117,183,181,118,132,128,184,150,168,121,179,132,168,182,119,117,180,120,175,177,116,175,128,163,181,178,123,118,172,143,163,157,179,122,121,119,157,122,150,180,137,177,125,123,172,125,137,143,120,178};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {157,157,132,163,181,180,150,116,181,125,125,119,119,163,132,143,172,172,179,178,150,121,120,118,168,123,178,137,120,117,182,117,175,177,175,168,183,123,184,128,118,122,179,122,180,121,182,183,128,177};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 21690886;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
