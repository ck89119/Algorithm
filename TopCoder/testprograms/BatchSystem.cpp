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
struct job
{
    string user;
    long long duration;
    vector<int> t;
};

int cmp(const job &a,const job &b)
{
    if (a.duration==b.duration) return a.t[0]<b.t[0];
    else return a.duration<b.duration;
}

class BatchSystem {
public:
	vector <int> schedule(vector <int>, vector <string>);
};

vector <int> BatchSystem::schedule(vector <int> duration, vector <string> user) {
    vector <int> ans;
    vector <job> list;
    map<string,vector<int> > tj1;
    map<string,long long> tj;
    int i,j;
    for (i=0;i<user.size();i++)
    {
        tj[user[i]]+=duration[i];
        tj1[user[i]].push_back(i);
          
    }
    map<string,long long>::const_iterator it=tj.begin();
    for (;it!=tj.end();it++)
    {
        job tmp;
        tmp.user=it->first;
        tmp.duration=it->second;
        tmp.t=tj1[tmp.user];
        list.push_back(tmp); 
    }
    sort(list.begin(),list.end(),cmp);
   // for (i=0;i<list.size();i++) {cout<<list[i].user<<" "<<list[i].duration<<endl;}
    for (i=0;i<list.size();i++)
    {
        int sz=list[i].t.size();
        for (j=0;j<sz;j++) ans.push_back(list[i].t[j]);
    }
    return ans;
        
}


double test0() {
	int t0[] = {42863029, 53617987, 24970877, 77828097, 51242, 55488287, 73174032, 28915543, 15040792, 8564629, 126792019, 45755106, 5574621, 34144659, 6808793, 65263189, 12446121, 126792019, 54239800, 14708377, 14322709, 77261063, 183031197, 78906834, 60701818, 12136954, 35933873, 80535700};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] =  {"NpkqAVxmmBTG", "qStmLcbnwszsWZHlRvHQWNfgTpSMoAum", "DfAxCQylYyDhVpfmaUvwTHkyNfNjkhQXcuzdAZgqsPJzrKl", "NpkqAVxmmBTG", "DfAxCQylYyDhVpfmaUvwTHkyNfNjkhQXcuzdAZgqsPJzrKl", "DfAxCQylYyDhVpfmaUvwTHkyNfNjkhQXcuzdAZgqsPJzrKl", "qStmLcbnwszsWZHlRvHQWNfgTpSMoAum", "nFCmErdwLoOlMboKzYUpVk", "nFCmErdwLoOlMboKzYUpVk", "uRcQ APlZwDtUSTaX", "DCQWnZjdLlyQXztQdXV", "NpkqAVxmmBTG", "nFCmErdwLoOlMboKzYUpVk", "DfAxCQylYyDhVpfmaUvwTHkyNfNjkhQXcuzdAZgqsPJzrKl", "uRcQ APlZwDtUSTaX", "uRcQ APlZwDtUSTaX", "lOTlDHrMelXxAWGNId", "X", "RXptLFPnszhbJluuKmTLjmmwrPQWjCD tSgGYfGaia", "NpkqAVxmmBTG", "NpkqAVxmmBTG", "nFCmErdwLoOlMboKzYUpVk", "lOTlDHrMelXxAWGNId", "uRcQ APlZwDtUSTaX", "RXptLFPnszhbJluuKmTLjmmwrPQWjCD tSgGYfGaia", "DfAxCQylYyDhVpfmaUvwTHkyNfNjkhQXcuzdAZgqsPJzrKl", "uRcQ APlZwDtUSTaX", "RXptLFPnszhbJluuKmTLjmmwrPQWjCD tSgGYfGaia"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystem * obj = new BatchSystem();
	clock_t start = clock();
	vector <int> my_answer = obj->schedule(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 6, 2, 4, 5, 13, 25, 7, 8, 12, 21, 10, 17, 0, 3, 11, 19, 20, 9, 14, 15, 23, 26, 16, 22, 18, 24, 27};
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
	int t0[] = {200, 200, 200};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Gil", "Sarah", "Warrick"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystem * obj = new BatchSystem();
	clock_t start = clock();
	vector <int> my_answer = obj->schedule(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {0, 1, 2 };
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
	int t0[] = {100, 200, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Horatio Caine", "horatio caine", "YEAAAAAAH"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystem * obj = new BatchSystem();
	clock_t start = clock();
	vector <int> my_answer = obj->schedule(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {2, 0, 1 };
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;system("pause");
}

//Powered by [KawigiEdit] 2.0!
