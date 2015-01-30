#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;

class TwoRectangles {
public:
	string describeIntersection(vector <int>, vector <int>);
};

string TwoRectangles::describeIntersection(vector <int> A, vector <int> B) {
//	if (A[0]>=B[0]&&A[0]<B[2]&&A[1]>=B[1]&&A[1]<B[3]) return "rectangle";
//	if (A[2]>B[0]&&A[2]<=B[2]&&A[3]>B[1]&&A[3]<=B[3]) return "rectangle";
//	if (A[0]>=B[0]&&A[0]<B[2]&&A[3]>B[1]&&A[3]<=B[3]) return "rectangle";
//	if (A[2]>B[0]&&A[2]<=B[2]&&A[1]>=B[1]&&A[1]<B[3]) return "rectangle";
//
//	if (B[0]>=A[0]&&B[0]<A[2]&&B[1]>=A[1]&&B[1]<A[3]) return "rectangle";
//	if (B[2]>A[0]&&B[2]<=A[2]&&B[3]>A[1]&&B[3]<=A[3]) return "rectangle";
//	if (B[0]>=A[0]&&B[0]<A[2]&&B[3]>A[1]&&B[3]<=A[3]) return "rectangle";
//	if (B[2]>A[0]&&B[2]<=A[2]&&B[1]>=A[1]&&B[1]<A[3]) return "rectangle";

    if (A[2]==B[0]&&A[1]<=B[1]&&A[3]>B[1]) return "segment";
    if (A[2]==B[0]&&A[1]>=B[1]&&A[1]<B[3]) return "segment";
    if (A[3]==B[1]&&A[0]<B[2]&&A[0]>=B[0]) return "segment";
    if (A[3]==B[1]&&B[0]>=A[0]&&B[0]<A[2]) return "segment";
    if (A[0]==B[2]&&A[1]<=B[1]&&A[3]>B[1]) return "segment";
    if (A[0]==B[2]&&A[1]>=B[1]&&A[1]<B[3]) return "segment";
    if (A[1]==B[3]&&A[0]>=B[0]&&A[0]<B[2]) return "segment";
    if (A[1]==B[3]&&A[0]<=B[0]&&A[2]>B[0]) return "segment";


	if (A[2]==B[0]&&A[3]==B[1]) return "point";
	if (A[0]==B[2]&&A[3]==B[1]) return "point";
	if (A[0]==B[2]&&A[1]==B[3]) return "point";
	if (A[2]==B[0]&&A[1]==B[3]) return "point";

	if (B[0]>A[2]||B[2]<A[0]||B[1]>A[3]||B[3]<A[1]) return "none";

	return "rectangle";



}


double test0() {
	int t0[] = {0,0,3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,1,5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoRectangles * obj = new TwoRectangles();
	clock_t start = clock();
	string my_answer = obj->describeIntersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "rectangle";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0,0,5,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoRectangles * obj = new TwoRectangles();
	clock_t start = clock();
	string my_answer = obj->describeIntersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "rectangle";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,1,6,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,2,5,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoRectangles * obj = new TwoRectangles();
	clock_t start = clock();
	string my_answer = obj->describeIntersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "segment";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0,1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,0,5,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoRectangles * obj = new TwoRectangles();
	clock_t start = clock();
	string my_answer = obj->describeIntersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "segment";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0,0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,1,5,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoRectangles * obj = new TwoRectangles();
	clock_t start = clock();
	string my_answer = obj->describeIntersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "point";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {1,1,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,1,4,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoRectangles * obj = new TwoRectangles();
	clock_t start = clock();
	string my_answer = obj->describeIntersection(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "none";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
