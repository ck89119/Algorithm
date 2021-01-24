/*
ID: ck891191
PROG:
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

int n,h,m,s,dh,dm,ds;

int output(){
    if (h>=10) printf("%d",h);
    else printf("0%d",h);
    printf(":");
    if (m>=10) printf("%d",m);
    else printf("0%d",m);
    printf(":");
    if (s>=10) printf("%d",s);
    else printf("0%d",s);
    printf("\n");
    return 0;
}

int main(){
    scanf("%d",&n);
    while (n--){
        char s1[15],s2[15];
        scanf("%s%s",s1,s2);
        h=((s1[0]-'0')*10+s1[1]-'0');
        m=((s1[3]-'0')*10+s1[4]-'0');
        s=((s1[6]-'0')*10+s1[7]-'0');

        dh=((s2[0]-'0')*10+s2[1]-'0');
        dm=((s2[3]-'0')*10+s2[4]-'0');
        ds=((s2[6]-'0')*10+s2[7]-'0');
        if (s-ds>=0) s-=ds;
        else{
            s=s+60-ds;
            dm++;
        }
        if (m-dm>=0) m-=dm;
        else{
            m=m+60-dm;
            dh++;
        }
        dh%=12;
        if (h-dh>=0) h-=dh;
        else h=h+12-dh;
        output();
    }
    return 0;
}
