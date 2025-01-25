#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int upper(char c){
    if (c>='A'&&c<='Z') return 1;
    else return 0;
}

int main(){
    int num[26];
    char str[80];
    int i,j,n;
    for (i=0;i<26;i++) num[i]=0;
    for (i=0;i<4;i++){
        gets(str);
        //printf("%s\n",str);
        for (j=0;j<strlen(str);j++)
            if (upper(str[j])) num[str[j]-'A']++;
    }
    n=0;
    for (i=0;i<26;i++)
        if (num[i]>n) n=num[i];
    for (i=n;i>0;i--){
        for (j=0;j<26;j++){
                if (num[j]>=i){
                    printf("*");
                    num[j]--;
                }
                else printf(" ");
                if (j!=25) printf(" ");

            }
        printf("\n");
    }
    for (j=0;j<26;j++) {
        printf("%c",'A'+j);
        if (j!=25) printf(" ");
    }
    printf("\n");
    return 0;
}
