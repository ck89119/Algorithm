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

int n;
char str[200005];

int main(){
    int num_i,num_a;
    int i;
    scanf("%d",&n);
    scanf("%s",str);
    num_i=0;num_a=0;
    for (i=0;i<n;i++)
        if (str[i]=='I') num_i++;
        else if (str[i]=='A') num_a++;
    if (num_i>1){
        printf("%d\n",0);
        return 0;
    }
    if (num_i==1){
        printf("%d\n",1);
        return 0;
    }
    printf("%d\n",num_a);
    return 0;
}
