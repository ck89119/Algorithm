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
class CircleMarket {
public:
	int makePurchases(vector <int>, vector <int>, int);
};

int CircleMarket::makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime) {
	int t=travelTime*openTime.size();
	int res=0,i;
	for (i=0;i<openTime.size();i++)
	{   
        int tt=travelTime*i; 
        if (closeTime[i]-openTime[i]>=t) {res++;continue;}
        while (openTime[i]-tt>0) 
        {
            openTime[i]-=t;
            closeTime[i]-=t;            
        }
        
        //dump(tt);
        //dump(openTime[i]);dump(closeTime[i]);
        if (openTime[i]<=travelTime*i&&closeTime[i]>=travelTime*i) res++;
    }
    return res;
    
   /* int max=0,res=0;
    int i,j;
    for (i=0;i<closeTime.size();i++) 
        if (max<closeTime[i]) max=closeTime[i];
    i=0;j=0;
    while (i<max)
    {
          if (j==openTime.size()) j=0;
          if (i>=openTime[j]&&i<=closeTime[j]) 
          {
               res++;dump(j);dump(i);
               dump(openTime[j]);dump(closeTime[j]);
               openTime[j]=0;
               closeTime[j]=-1;
               
          }
          j++;
          i+=travelTime;
    
    }
    return res;*/
}


double test0() {
	int t0[] = {2733, 593166, 396013} ;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3058, 593530, 396370};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 137;
	CircleMarket * obj = new CircleMarket();
	clock_t start = clock();
	int my_answer = obj->makePurchases(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {45, 45, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {50, 50, 20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 15;
	CircleMarket * obj = new CircleMarket();
	clock_t start = clock();
	int my_answer = obj->makePurchases(p0, p1, p2);
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
double test2() {
	int t0[] = {1000, 1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1010, 1010};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	CircleMarket * obj = new CircleMarket();
	clock_t start = clock();
	int my_answer = obj->makePurchases(p0, p1, p2);
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
double test3() {
	int t0[] = {999999, 2, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000000, 22, 44};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	CircleMarket * obj = new CircleMarket();
	clock_t start = clock();
	int my_answer = obj->makePurchases(p0, p1, p2);
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
double test4() {
	int t0[] = {363, 237, 382, 232, 392, 3829, 99999, 12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {365, 1239, 2384, 234, 394, 3831, 100001, 15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	CircleMarket * obj = new CircleMarket();
	clock_t start = clock();
	int my_answer = obj->makePurchases(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
