/*
ID: ck89119
PROG: POJ1654
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

int main(){
    int t,i,a,b,minus;
    char s[1000005];
    scanf("%d",&t);
    while (t--){
        scanf("%s",s);
        a=0;b=0;minus=0;
        for (i=0;s[i]!='5';i++){
            if (s[i]=='1'||s[i]=='2'||s[i]=='3') a++;
            if (s[i]=='3'||s[i]=='6'||s[i]=='9') b++;
            if (s[i]=='1'||s[i]=='7'||s[i]=='3'||s[i]=='9') minus++;
        }
        if (minus%2){
            double ret=a*b-0.5*minus;
            printf("%.1f\n",ret);
        }
        else printf("%d\n",a*b-minus/2);
    }
    return 0;
}
