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
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
bool cmp(const int& a,const int& b)
{
     return a>b;
}
class TheCoffeeTimeDivTwo {
public:
	int find(int, vector <int>);
};

int TheCoffeeTimeDivTwo::find(int n, vector <int> tea) {
	bool d[1010]={0};
	int i,ret=0;
	for (i=0;i<tea.size();i++) d[tea[i]]=1;
    sort(tea.begin(),tea.end(),cmp);
    for (i=0;i<tea.size();) 
    {
        if (tea.size()-i>=7) 
        {
             ret=ret+47+28+2*(tea[i]);
             i+=7;
        }
        else 
        {
             ret=ret+47+4*(tea.size()-i)+2*(tea[i]);
             i=tea.size();
        }
    }//dump(ret);
    int tmp1=0,tmp2=0; 
    for (i=n;i>0;i--)
    {
        if (!d[i])
        {
            if (tmp1==0) tmp2=i;
            tmp1++;
        } 
        if (tmp1==7)
        {
            tmp1=0;
            ret=ret+47+tmp2*2+28;
        }
    }
	if (tmp1!=0) ret=ret+47+tmp2*2+4*tmp1;
	return ret;
}


double test0() {
	int p0 = 2;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheCoffeeTimeDivTwo * obj = new TheCoffeeTimeDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 108;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 2;
	int t1[] = {2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheCoffeeTimeDivTwo * obj = new TheCoffeeTimeDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 59;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 15;
	int t1[] = {1, 2, 3, 4, 5, 6, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheCoffeeTimeDivTwo * obj = new TheCoffeeTimeDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 261;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 47;
	int t1[] = {1, 10, 6, 2, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheCoffeeTimeDivTwo * obj = new TheCoffeeTimeDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 891;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;system("pause");
}

//Powered by [KawigiEdit] 2.0!
