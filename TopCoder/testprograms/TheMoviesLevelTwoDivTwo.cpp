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

class TheMoviesLevelTwoDivTwo {
public:
	vector <int> find(vector <int>, vector <int>);
	bool next(vector <int>&);
};

vector <int> TheMoviesLevelTwoDivTwo::find(vector <int> length, vector <int> scary) {
	 vector <int> l(length.size(),0);
	 vector <int> ret(length.size(),0);	 
	 int sum=0;	 	  
	 for (int i=0;i<length.size();i++) {l[i]=i;ret[i]=i;}
	 do
	 {
           int t=74,s=0;
           for (int i=0;i<length.size();i++) cout<<l[i]<<' ';
           cout<<'\n';
           for (int i=0;i<l.size();i++)
           {
               if (t>=scary[l[i]]&&t+47>=length[l[i]]){
                   s++;
                   t=t+47-length[l[i]];
               }
               else break;       
           }
           if (s>sum) 
           {
               sum=s;
               for (int i=0;i<l.size();i++) ret[i]=l[i];
           }      
     }while (next(l));
	 return ret;	 
}

bool TheMoviesLevelTwoDivTwo::next(vector <int> &t){
     int i=t.size()-1,j;
     while (i>0){
        j=i;
        while (j>0&&t[j]<t[j-1]) j--; 
        int min=t[j],minn=j;
        for (int k=j;k<t.size();k++) 
            if (t[k]>t[j-1]&&min>t[k]) {
                min=t[k];  
                minn=k;
                }                    
        if (j>0)
        {
           int tt=t[minn];
           t[minn]=t[j-1];
           t[j-1]=tt;
           for (int k=j;k<t.size()-1;k++)
              for (int kk=k+1;kk<t.size();kk++)
                 if (t[k]>t[kk])
                 {
                     int tmp=t[k];
                     t[k]=t[kk];
                     t[kk]=tmp;
                 }
           return true;
       }
       i--; 
     } 
     return false;       
}



double test0() {
	int t0[] = {100, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheMoviesLevelTwoDivTwo * obj = new TheMoviesLevelTwoDivTwo();
	clock_t start = clock();
	vector <int> my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {0, 1 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {100, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 49};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheMoviesLevelTwoDivTwo * obj = new TheMoviesLevelTwoDivTwo();
	clock_t start = clock();
	vector <int> my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {100, 100, 100, 100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {77, 76, 75, 74};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheMoviesLevelTwoDivTwo * obj = new TheMoviesLevelTwoDivTwo();
	clock_t start = clock();
	vector <int> my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {3, 0, 1, 2 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {99};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TheMoviesLevelTwoDivTwo * obj = new TheMoviesLevelTwoDivTwo();
	clock_t start = clock();
	vector <int> my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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
		cout <<"Some of the test cases had errors." <<endl;
    system("pause");
    //int i; cin>>i;   
}

//Powered by [KawigiEdit] 2.0!
