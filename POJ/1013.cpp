/*
ID: ck89119
PROG: POJ1013
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
    int n,w[12],l[12],i,k,m,weight,in[12];
    char left[12],right[12],position[12];
    scanf("%d",&n);
    while (n--){
        for (i=0;i<12;i++) {w[i]=0;l[i]=0;}
        for (k=0;k<3;k++){
            scanf("%s %s %s",left,right,position);
            //printf("%s\n",left);
            if (strcmp(position,"even")==0){
                for (i=0;left[i];i++) {w[left[i]-'A']=-100;l[left[i]-'A']=-100;}
                for (i=0;right[i];i++) {w[right[i]-'A']=-100;l[right[i]-'A']=-100;}
            }
            else if (strcmp(position,"up")==0){
                for (i=0;i<12;i++) in[i]=0;
                for (i=0;left[i];i++) {in[left[i]-'A']=1;in[right[i]-'A']=1;}
                for (i=0;i<12;i++)
                    if (!in[i]) {w[i]=-100;l[i]=-100;}
                for (i=0;left[i];i++) {w[left[i]-'A']++;l[right[i]-'A']++;}
            }
            else {
                for (i=0;i<12;i++) in[i]=0;
                for (i=0;left[i];i++) {in[left[i]-'A']=1;in[right[i]-'A']=1;}
                for (i=0;i<12;i++)
                    if (!in[i]) {w[i]=-100;l[i]=-100;}
                for (i=0;left[i];i++)  {l[left[i]-'A']++;w[right[i]-'A']++;}
            }
        }
        m=0;weight=0;k=-1;
        for (i=0;i<12;i++){
            if (w[i]>m) {m=w[i];k=i;weight=1;}
            if (l[i]>m) {m=l[i];k=i;weight=-1;}
        }
        if (weight==-1) printf("%c is the counterfeit coin and it is light.\n",'A'+k);
        else  printf("%c is the counterfeit coin and it is heavy.\n",'A'+k);
    }
    return 0;
}
