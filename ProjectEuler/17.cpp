/*
ID: ck89119
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
const int len_and=3;
const int len_hundred=7;
const int len1[21]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6};
const int len2[10]={0,3,6,6,5,5,5,7,6,6};
int main(){
    int i,j,ans=11;
    for (i=1;i<=999;i++){
        if (i>=100){
            if (i%100==0)
                ans+=len1[i/100]+len_hundred;
            else ans+=len1[i/100]+len_hundred+len_and;
        }
        j=i%100;
        if (j<=20)
            ans+=len1[j];
        else
            ans+=len2[j/10]+len1[j%10];
    }
    printf("%d\n",ans);
    return 0;
}
