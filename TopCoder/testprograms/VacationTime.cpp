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

class VacationTime {
public:
	int bestSchedule(int, int, vector <int>);
};

int VacationTime::bestSchedule(int N, int K, vector <int> workingDays) {
	int min=60,a[1010]={0};
    int i,j;
    sort(workingDays.begin(),workingDays.end());
    for (i=0;i<workingDays.size();i++)
    {
        for (j=workingDays[i];j>=1&&j>=workingDays[i]-K+1;j--) a[j]++;
       /* 
        if (workingDays[i]<=N-K+1) 
           for (j=i;j<i+K)a[workingDays[i]]++;
        if (workingDays[i]>K) a[workingDays[i]-K]--;*/
    }
	for (i=1;i<=N-K+1;i++) 
	    if (a[i]<min) min=a[i];
    return min;
	
	
}


double test0() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	VacationTime * obj = new VacationTime();
	clock_t start = clock();
	int my_answer = obj->bestSchedule(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 4;
	int p1 = 3;
	int t2[] = {3, 1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	VacationTime * obj = new VacationTime();
	clock_t start = clock();
	int my_answer = obj->bestSchedule(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 3;
	int t2[] = {4, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	VacationTime * obj = new VacationTime();
	clock_t start = clock();
	int my_answer = obj->bestSchedule(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 9;
	int p1 = 2;
	int t2[] = {7, 4, 5, 6, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	VacationTime * obj = new VacationTime();
	clock_t start = clock();
	int my_answer = obj->bestSchedule(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 1000;
	int p1 = 513;
	int t2[] = {808, 459, 792, 863, 715, 70, 336, 731};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	VacationTime * obj = new VacationTime();
	clock_t start = clock();
	int my_answer = obj->bestSchedule(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
		cout <<"Some of the test cases had errors." <<endl;system("pause");
}

//Powered by [KawigiEdit] 2.0!
