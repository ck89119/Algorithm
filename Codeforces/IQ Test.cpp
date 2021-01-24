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
int c[5][5];

int main(){
    char str[10];
    int i,j;
    for (i=0;i<4;i++){
        scanf("%s",str);
        for (j=0;j<8;j++)
            if (str[j]=='#') c[i][j]=1;
            else c[i][j]=0;
    }
    for (i=0;i<3;i++)
        for (j=0;j<3;j++){
            int s=0;
            s=c[i][j]+c[i+1][j]+c[i][j+1]+c[i+1][j+1];
            if (s>=3||s<=1){
                printf("YES\n");
                return 0;
            }
        }

    printf("NO\n");
    return 0;
}
