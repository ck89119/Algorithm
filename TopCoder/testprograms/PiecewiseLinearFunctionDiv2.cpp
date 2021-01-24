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


class PiecewiseLinearFunctionDiv2 {
public:
    int in(int a, int b, int c) {
        if (a < b) {
            if (c > a && c <= b) return 1;
            else return 0;
        }
        else if (a > b) {
            if (c < a && c >= b) return 1;
            else return 0;
        }
        else {
            if (c == a) return -1;
            else return 0;
        }
    }

    int in1(int a, int b, int c) {
        if (a < b) {
            if (c >= a && c <= b) return 1;
            else return 0;
        }
        else if (a > b) {
            if (c <= a && c >= b) return 1;
            else return 0;
        }
        else {
            if (c == a) return -1;
            else return 0;
        }
    }

	vector <int> countSolutions(vector <int> Y, vector <int> query) {
		int n = Y.size();
		int i;
		vector<int> res;
		for (i = 0; i < query.size(); i++) {
            int k, tmp;
            tmp = 0;
            if (in1(Y[0], Y[1], query[i]) == -1) {
                tmp = -1;
                res.push_back(tmp);
                continue;
            }
            else tmp += in1(Y[0], Y[1], query[i]);

            for (k = 2; k < n; k++) {
                int t = in(Y[k-1], Y[k], query[i]);
                if (t == -1) {
                    tmp = -1;
                    break;
                }
                else tmp += t;
            }
            res.push_back(tmp);
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, vector <int> p2) {
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
	PiecewiseLinearFunctionDiv2 *obj;
	vector <int> answer;
	obj = new PiecewiseLinearFunctionDiv2();
	clock_t startTime = clock();
	answer = obj->countSolutions(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p2[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p2;

	{
	// ----- test 0 -----
	int t0[] = {1,4,-1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-2,-1,0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,-1,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {2,4,8,0,3,-6,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1,2,3,4,0,65536};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {3,4,5,4,3,3,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {-178080289,-771314989,-237251715,-949949900,-437883156,-835236871,-316363230,-929746634,-671700962};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-673197622,-437883156,-251072978,221380900,-771314989,-949949900,-910604034,-671700962,-929746634,-316363230};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {8,6,3,0,7,1,4,8,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
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
