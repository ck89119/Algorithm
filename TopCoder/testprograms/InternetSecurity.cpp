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
class InternetSecurity {
public:
	vector <string> determineWebsite(vector <string>, vector <string>, vector <string>, int);
};

vector <string> InternetSecurity::determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold) {
set <string> s;
vector <string> ans;
vector <string> kd[address.size()];
vector <int> vis(address.size(),0);
int i;
bool update;

for (i=0;i<dangerous.size();i++)
{
    s.insert(dangerous[i]);
}

for (i=0;i<keyword.size();i++)
{
    istringstream iss(keyword[i]);
    string str;
    while (iss>>str)
    {
          kd[i].push_back(str);
         // dump(str);system("pause");
    }
   // dump("###");
}

update=true;
while (update)
{
      int num,j;
      update=false;
      for (i=0;i<address.size();i++)
      {          
           num=0;
           if (vis[i]) continue;
           for (j=0;j<kd[i].size();j++)
           {
                //dump(kd[i][j]);system("pause");
               if (s.find(kd[i][j])!=s.end()) num++;//dump(j);system("pause");}
           }          
           if (num>=threshold) 
           {
               for (j=0;j<kd[i].size();j++) s.insert(kd[i][j]);
               vis[i]=1;
               update=true;
           }
      }
      
}

for (i=0;i<address.size();i++) 
   if (vis[i]) ans.push_back(address[i]);   

return ans; 
}


double test0() {
	string t0[] = {"www.topcoder.com",
"www.sindicate_of_evil.com",
"www.happy_citizens.com"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"hack encryption decryption internet algorithm",
"signal interference evil snake poison algorithm",
"flower baloon topcoder blue sky sea"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"hack","encryption","decryption","interference","signal","internet"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 3;
	InternetSecurity * obj = new InternetSecurity();
	clock_t start = clock();
	vector <string> my_answer = obj->determineWebsite(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t4[] = {"www.topcoder.com", "www.sindicate_of_evil.com" };
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<"\""<<p4[0]<<"\"";
		for (int i=1; i<p4.size(); i++)
			cout <<", \"" <<p4[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"brokenlink","flowerpower.net","purchasedomain.com"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"broken","rose tulips","cheap free domain biggest greatest"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"biggest","enemy","hideout"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 2;
	InternetSecurity * obj = new InternetSecurity();
	clock_t start = clock();
	vector <string> my_answer = obj->determineWebsite(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <string> p4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<"\""<<p4[0]<<"\"";
		for (int i=1; i<p4.size(); i++)
			cout <<", \"" <<p4[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"a..a.ab.","...aa.b"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"a bc def","def ghij klmno"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"a","b","c","d","e"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 1;
	InternetSecurity * obj = new InternetSecurity();
	clock_t start = clock();
	vector <string> my_answer = obj->determineWebsite(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t4[] = {"a..a.ab.", "...aa.b" };
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<"\""<<p4[0]<<"\"";
		for (int i=1; i<p4.size(); i++)
			cout <<", \"" <<p4[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"www.tsa.gov"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"information assurance signal intelligence research"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"signal","assurance","penguin"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 2;
	InternetSecurity * obj = new InternetSecurity();
	clock_t start = clock();
	vector <string> my_answer = obj->determineWebsite(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t4[] = {"www.tsa.gov" };
	vector <string> p4(t4, t4+sizeof(t4)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<"\""<<p4[0]<<"\"";
		for (int i=1; i<p4.size(); i++)
			cout <<", \"" <<p4[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
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
