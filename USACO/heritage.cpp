/*
ID: ck891191
PROG: heritage
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
char in_order[30],pre_order[30];

int input(){
    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
    scanf("%s%s",in_order,pre_order);
    //dump(in_order);dump(pre_order);
    return 0;
}

int post(int in1,int in2,int pre1,int pre2){
    int i,j;
    if (in2==in1) return 0;
    if (in2-in1==1){
        printf("%c",pre_order[pre1]);
        return 0;
    }
    i=in1;
    while (in_order[i]!=pre_order[pre1]) i++;
    post(in1,i,pre1+1,pre1+i-in1+1);
    post(i+1,in2,pre1+i-in1+1,pre2);
    printf("%c",pre_order[pre1]);
    return 0;
}

int main(){
    input();
    post(0,strlen(in_order),0,strlen(pre_order));
    printf("\n");
    return 0;
}
