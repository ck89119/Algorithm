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


class EelAndRabbit {
public:
	int getmax(vector <int> l, vector <int> t) {
		set<int> s;
		set<int>::iterator it;
		vector<int> p;
		int i, j, k, size;
		int res;
		size = l.size();
		for (i = 0; i < size; i++) {
		    s.insert(t[i]);
		    s.insert(t[i]+l[i]);
		}
		for (it = s.begin(); it != s.end(); it++)
            p.push_back(*it);
		//sort(p.begin(), p.end());
        //for (i = 0; i < p.size(); i++) cout << p[i] << ' '; cout << endl;

		int size2;
		int v[size], v1[size];
		size2 = p.size();//dump(size2)
		res = 0;
		for (i = 0; i < size2; i++) {
		    int tmp = 0;
		    CL(v, 0);
		    for (k = 0; k < size; k++)
                if (!v[k] && p[i] >= t[k] && p[i] <= t[k]+l[k]) {
                    v[k] = 1;
                    tmp++;
                }
            for (j = i+1; j < size2; j++) {
                int tmp2 = tmp;
                for (k = 0; k < size; k++) v1[k] = v[k];
                for (k = 0; k < size; k++)
                    if (!v1[k] && p[j] >= t[k] && p[j] <= t[k]+l[k]) {
                        v1[k] = 1;
                        tmp2++;
                    }
                res = max(res, tmp2);
            }
		}
		return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	EelAndRabbit *obj;
	int answer;
	obj = new EelAndRabbit();
	clock_t startTime = clock();
	answer = obj->getmax(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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

	vector <int> p0;
	vector <int> p1;
	int p2;

	{
	// ----- test 0 -----
	int t0[] = {2,4,3,2,2,1,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,6,3,7,0,2,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,0,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {8,2,1,10,8,6,3,1,2,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {17,27,26,11,1,27,23,12,11,13};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
