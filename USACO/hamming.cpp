/*
ID: ck891191
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,b,d,ret_size;
char ret[70][10];
int init(){
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    scanf("%d%d%d",&n,&b,&d);
    ret_size=0;
    return 0;
}

int ham_dis(char sa[10],char sb[10]){
    int i,ret=0;
    for (i=0;i<b;i++)
        if (sa[i]!=sb[i]) ret++;
    return ret;
}

int intToStr(int ia,char sa[10]){
    int i;
    for (i=0;i<b;i++){
        if (ia!=0){
            sa[i]='0'+ia%2;
            ia/=2;
        }
        else sa[i]='0';
    }
    return 0;
}

int strToInt(char sa[10]){
    int i,ret;
    ret=0;
    for (i=b-1;i>=0;i--)
        ret=ret*2+sa[i]-'0';
    return ret;
}

int solve(){
    int i,x,flag;
    char tmp[10];
    intToStr(0,tmp);
    strcpy(ret[ret_size++],tmp);
    x=1;
    while (ret_size<n){
        intToStr(x,tmp);
        flag=1;
        for (i=0;i<ret_size;i++)
            if (ham_dis(tmp,ret[i])<d){
                flag=0;
                break;
            }
        if (flag) strcpy(ret[ret_size++],tmp);
        x++;
    }
    return 0;
}

int print(){
    int i;
    for (i=0;i<n;i++){
        if (i%10) printf(" %d",strToInt(ret[i]));
        else printf("%d",strToInt(ret[i]));
        if (i%10==9) printf("\n");
    }
    if (n%10!=0) printf("\n");
}

int main(){
    init();
    solve();
    print();
    return 0;
}
