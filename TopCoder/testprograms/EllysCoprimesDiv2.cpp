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

int arr[100000+5];

int gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}

int solve(int a,int b) {
    int da[1000],db[1000];
    int da_size,db_size;
    int ta,tb;
    int i;
    if (gcd(a,b)==1) return 0;
    da_size=db_size=0;
    ta=a;tb=b;
    for (i=2;i<=ta;i++){
        if (ta%i==0){
            da[da_size++]=i;
            while (ta%i==0) ta/=i;
        }
        if (ta==1) break;
    }

    for (i=2;i<=tb;i++){
        if (tb%i==0){
            db[db_size++]=i;
            while (tb%i==0) tb/=i;
        }
        if (tb==1) break;
    }

    for (i=a;i<=b;i++) arr[i]=0;
    for (i=0;i<da_size;i++){
        int j=a+da[i];
        while (j<b) {arr[j]=1;j+=da[i];}
    }
    for (i=0;i<db_size;i++){
        int j=b-db[i];
        while (j>a) {arr[j]=1;j-=db[i];}
    }

    for (i=a+1;i<=b-1;i++)
        if (arr[i]==0) return 1;
    return 2;
}

class EllysCoprimesDiv2 {
public:

	int getCount(vector <int> numbers) {
        int ans=0;
        int i;
        sort(numbers.begin(),numbers.begin()+numbers.size());
        for (i=0;i<numbers.size()-1;i++)
            ans+=solve(numbers[i],numbers[i+1]);
        return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	EllysCoprimesDiv2 *obj;
	int answer;
	obj = new EllysCoprimesDiv2();
	clock_t startTime = clock();
	answer = obj->getCount(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	int p1;

	{
	// ----- test 0 -----
	int t0[] = {2200,42,2184,17};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {13,1,6,20,33};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {7,42};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {55780,44918,55653,4762,41536,40083,79260,7374,24124,91858,7856,12999,64025,12706,19770,71495,32817,79309,53779,8421,97984,34586,893,64549,77792,12143,52732,94416,54207,51811,80845,67079,14829,25350,22976,23932,62273,58871,82358,13283,33667,64263,1337,42666};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
