/*
ID: ck891191
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cstdlib>
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
const double EPS=1e-15;
class DiceThrows {
public:
	double winProbability(int numDiceA, vector <int> sidesA, int numDiceB, vector <int> sidesB) {
		double pa[20005],pa1[20005],pb[20005],pb1[20005];
		double res;
		int maxa,maxb;
		maxa=maxb=0;
		FR(i,0,6){
            maxa=max(maxa,sidesA[i]);
            maxb=max(maxb,sidesB[i]);
		}
		//dump(maxa);dump(maxb);
		FR(i,0,maxa*numDiceA+1) pa[i]=0.0;
		FR(i,0,maxb*numDiceB+1) pb[i]=0.0;
		pa[0]=1.0;pb[0]=1.0;
		FR(k,1,numDiceA+1){
		    FR(i,0,maxa*numDiceA+1) pa1[i]=0.0;
		    FR(i,0,maxa*numDiceA+1)FR(j,0,6)
                if (i-sidesA[j]>=0) pa1[i]+=pa[i-sidesA[j]]/6;
            FR(i,0,maxa*numDiceA+1) pa[i]=pa1[i];
            //FR(i,0,maxa*numDiceA+1) cout<<pa[i]<<' ';cout<<endl;
		}
		FR(k,1,numDiceB+1){
		    FR(i,0,maxb*numDiceB+1) pb1[i]=0.0;
		    FR(i,0,maxb*numDiceB+1)FR(j,0,6)
                if (i-sidesB[j]>=0) pb1[i]+=pb[i-sidesB[j]]/6;
            FR(i,0,maxb*numDiceB+1) pb[i]=pb1[i];
		}
		//FR(i,0,maxa*numDiceA+1) cout<<pa[i]<<' ';cout<<endl;
		//FR(i,0,maxb*numDiceB+1) cout<<pb[i]<<' ';cout<<endl;
		res=0;
        FR(i,0,maxa*numDiceA+1) if (pa[i]>EPS){
            double tmp=0.0;
            FR(j,0,i){
                tmp+=pb[j];
            }
            res+=pa[i]*tmp;
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, int p2, vector <int> p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2 << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	DiceThrows *obj;
	double answer;
	obj = new DiceThrows();
	clock_t startTime = clock();
	answer = obj->winProbability(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
	int p2;
	vector <int> p3;
	double p4;

	{
	// ----- test 0 -----
	p0 = 1;
	int t1[] = {1,2,3,4,5,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	int t3[] = {1,2,3,4,5,6};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.41666666666666663;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 200;
	int t1[] = {1,3,8,18,45,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 80;
	int t3[] = {1,4,10,21,53,100};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.25240407058279035;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	int t1[] = {1,1,1,2,2,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	int t3[] = {1,1,1,1,1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.25;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 200;
	int t1[] = {6,5,4,3,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 200;
	int t3[] = {3,4,6,5,1,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.49416239842107595;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 100;
	int t1[] = {1,1,1,1,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 199;
	int t3[] = {1,1,1,1,1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 1.5306467074865068E-78;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
