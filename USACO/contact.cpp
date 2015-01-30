/*
ID: ck891191
PROG: contact
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
string str;
int a,b,n,pat_size;
map<string, int> times;
struct p{
    string s;
    int times;
}pat[10000];

int input(){
    string t;
    freopen("contact.in","r",stdin);
    scanf("%d %d %d",&a,&b,&n);
    getchar();
    while (cin>>t) {
        str+=t;
    }
    return 0;
}

int cmp(const p &a,const p &b){
    if (a.times>b.times) return 1;
    if (a.times<b.times) return 0;
    if (a.times==b.times){
        if (a.s.size()<b.s.size()) return 1;
        if (a.s.size()>b.s.size()) return 0;
        if (a.s.size()==b.s.size()) return a.s<b.s;
    }
}

//int cmp1(const pair<string, int> &a,const pair<string, int> &b){
//    if (a.second>b.second) return 1;
//    if (a.second<b.second) return 0;
//    if (a.second==b.second){
//        if (a.first.size()<b.first.size()) return 1;
//        if (a.first.size()>b.first.size()) return 0;
//        if (a.first.size()==b.first.size()) return a.first<b.first;
//    }
//}

int solve(){
    int i,j;
    string tmp;
    map<string, int>::const_iterator map_it;
    for (i=0;i<str.size();i++)
        for (j=a;j<=b;j++)
            if (i-j+1>=0){
                tmp=str.substr(i-j+1,j);
                times[tmp]++;
            }
//    sort(times.begin(),times.end(),cmp1);
    pat_size=0;
    for (map_it=times.begin();map_it!=times.end();map_it++,pat_size++) {
        pat[pat_size].s=map_it->first;
        pat[pat_size].times=map_it->second;
    }
    sort(pat,pat+pat_size,cmp);
    return 0;
}

int output(){
    int i,j,k,count,pre;
    freopen("contact.out","w",stdout);
    count=0;pre=0;
    for (i=0;count<n&&i<pat_size;i++){
        if (pat[i].times==pat[i+1].times) continue;
        printf("%d\n",pat[i].times);
        k=1;
        for (j=pre;j<i;j++){
            if (k) cout<<pat[j].s<<' ';
            else cout<<pat[j].s<<endl;
            k=(k+1)%6;
        }
        cout<<pat[i].s<<endl;
        pre=i+1;count++;
    }
}

int main(){
    input();
    solve();
    output();
    return 0;
}
