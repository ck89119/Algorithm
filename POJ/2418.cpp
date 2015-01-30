/*
ID: ck89119
PROG: POJ2418
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
//typedef char name[40];


int main()
{
    int total=0;
    map<string,int> spe;
    map<string,int>::iterator iter;
    string t;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while (getline(cin,t)){
        total++;
        spe[t]++;
    }
    for (iter=spe.begin();iter!=spe.end();iter++){
        cout<<iter->first<<' ';
        printf("%.4lf\n",(iter->second)*100.0/total);
    }
    return 0;
}
