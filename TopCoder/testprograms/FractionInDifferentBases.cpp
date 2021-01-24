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

class FractionInDifferentBases {
public:
	long long getNumberOfGoodBases(long long, long long, long long, long long);
	long long gcd(long long a,long long b);
};

long long FractionInDifferentBases::gcd(long long a,long long b){
    if (a%b==0) return b;
    else return gcd(b,a%b);
}

long long FractionInDifferentBases::getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
	long long d,y,i;
	long long finite;
	d=gcd(P,Q);
	P/=d;Q/=d;
	y=1;
	for (i=2;i*i<=Q;i++)
        if (Q%i==0){
            y*=i;
            while (Q%i==0) Q/=i;
        }
    y*=Q;
    finite=B/y-(A-1)/y;
	return (B-A+1-finite);
}


double test0() {
	long long p0 = 1LL;
	long long p1 = 2LL;
	long long p2 = 10LL;
	long long p3 = 10LL;
	FractionInDifferentBases * obj = new FractionInDifferentBases();
	clock_t start = clock();
	long long my_answer = obj->getNumberOfGoodBases(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	long long p0 = 1LL;
	long long p1 = 9LL;
	long long p2 = 9LL;
	long long p3 = 10LL;
	FractionInDifferentBases * obj = new FractionInDifferentBases();
	clock_t start = clock();
	long long my_answer = obj->getNumberOfGoodBases(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 1LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	long long p0 = 5LL;
	long long p1 = 6LL;
	long long p2 = 2LL;
	long long p3 = 10LL;
	FractionInDifferentBases * obj = new FractionInDifferentBases();
	clock_t start = clock();
	long long my_answer = obj->getNumberOfGoodBases(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 8LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	long long p0 = 2662LL;
	long long p1 = 540LL;
	long long p2 = 2LL;
	long long p3 = 662LL;
	FractionInDifferentBases * obj = new FractionInDifferentBases();
	clock_t start = clock();
	long long my_answer = obj->getNumberOfGoodBases(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 639LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	long long p0 = 650720LL;
	long long p1 = 7032600LL;
	long long p2 = 2012LL;
	long long p3 = 2012540LL;
	FractionInDifferentBases * obj = new FractionInDifferentBases();
	clock_t start = clock();
	long long my_answer = obj->getNumberOfGoodBases(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 2010495LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
