/*
ID: ck891191
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char pri_set[205][15];
char str[200005];
int pset_size,str_index[200005];
int init(){
    char tmp[80];
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    pset_size=0;
    while (scanf("%s",tmp),strcmp(tmp,".")!=0){
        strcpy(pri_set[pset_size],tmp);
        pset_size++;
    }
    while (scanf("%s",tmp)!=EOF){
        strcat(str,tmp);
    }
    memset(str_index,0,sizeof(str_index));
    //cout<<str<<endl;
    return 0;
}

int solve(){
    int update,i,j,longest;
    longest=0;
    for (i=0;i<strlen(str);i++){
        for (j=0;j<pset_size;j++)
            if (i+strlen(pri_set[j])<=longest) continue;
            else if (strncmp(str+i,pri_set[j],strlen(pri_set[j]))==0)
                    longest=i+strlen(pri_set[j]);
        if (i>=longest) break;
    }
    printf("%d\n",longest);
    return 0;
}
int main(){
    init();
    solve();
    return 0;
}
